/*** VisSim Automatic Code Generator ***/
/*  Output for D:\VISSIM30\multi_cavity\orifice_a.vsm at Sat Feb 07 17:40:34 1998 */


#include "math.h"
#include "cgen.h"
#include "cgendll.h"

extern CGDOUBLE T,Zed;

CGDOUBLE _pt_vol_1;
CGDOUBLE _p_local_1;
CGDOUBLE _mflow_1;
CGDOUBLE _pr_1;
CGDOUBLE _Gm_1;
CGDOUBLE _Mtr_1;
CGDOUBLE _Cd_1;
CGDOUBLE _Cd_91;
CGDOUBLE _M_91;
CGDOUBLE _M_p_91;
CGDOUBLE _Gm_91;
CGDOUBLE _G_91;
CGDOUBLE _WD_91;
CGDOUBLE _k_1=1;
CGDOUBLE _k_91;
CGDOUBLE _A_1;
CGDOUBLE _A_91;
CGDOUBLE _pt_1;
CGDOUBLE _Pt_91;
CGDOUBLE _Tt_vol_1;
CGDOUBLE _Tt_local_1;
CGDOUBLE _Tt_1;
CGDOUBLE _Tt_91;
CGDOUBLE _Wdot_91;
CGDOUBLE _Wdtr_1;
CGDOUBLE __dW_in_dtr_1;
CGDOUBLE __dTw_Wdt_dtr_1;
DLL_SIG_DECL(7,4)
DLL_FUNC_DEF(Orifice)

void OrificeDeriv()
{
  int t32;
  CGDOUBLE t67;
  CGDOUBLE t70;
  CGDOUBLE t76;
  CGDOUBLE t61;
  _pt_vol_1 =  inSig[4] ;
  _p_local_1 =  inSig[2] ;
  _mflow_1 = (( _pt_vol_1 ==0.)?0.:(( _pt_vol_1 > _p_local_1 )?-1.:1.));
  t32 = ( _mflow_1 ==-1.);
  _pr_1 = ( t32 ?(( _pt_vol_1 )/( _p_local_1 )):(( _p_local_1 )/( _pt_vol_1 )));
  _Gm_1 =  inSig[6] ;
  t67 = ( - 1.+ _Gm_1 );
  t70 = (( t67 )/( _Gm_1 ));
  t76 = (pow( _pr_1 , t70 ));
  t61 = ( _mflow_1 *pow((((2.*( t76 -1.)))/( t67 )),0.5));
  _Mtr_1 = (( fabs( t61 )>1.)? _mflow_1 : t61 );
  _Cd_1 =  inSig[1] ;
  _Cd_91 =  _Cd_1 ;
  _M_91 =  fabs( _Mtr_1 );
  _M_p_91 = (( _M_91 >=1.)?1.: _M_91 );
  _Gm_91 =  _Gm_1 ;
  _G_91 = ( _Gm_91 -1.);
  _WD_91 = ( _M_p_91 *(pow(((pow( _M_p_91 ,2)*0.5* _G_91 )+1.),(-0.5*(((1.+ _Gm_91 ))/( _G_91 ))))));
  _k_91 =  _k_1 ;
  _A_1 =  inSig[0] ;
  _A_91 =  _A_1 ;
  _pt_1 = ( t32 ? _pt_vol_1 : _p_local_1 );
  _Pt_91 =  _pt_1 ;
  _Tt_vol_1 =  inSig[5] ;
  _Tt_local_1 =  inSig[3] ;
  _Tt_1 = (( _mflow_1 ==-1.)? _Tt_vol_1 : _Tt_local_1 );
  _Tt_91 =  _Tt_1 ;
  _Wdot_91 = ((( _Cd_91 * _WD_91 * _k_91 * _A_91 * _Pt_91 ))/(pow( _Tt_91 ,0.5)));
  _Wdtr_1 = ( _mflow_1 * _Wdot_91 );
  __dW_in_dtr_1 = (( _Wdtr_1 >0.)? _Wdtr_1 :0.);
  __dTw_Wdt_dtr_1 = (( _Wdtr_1 >0.)?((( _Wdtr_1 * _Tt_1 ))/(((( _Gm_1 -1.)*0.5*pow( fabs( _Mtr_1 ),2))+1.))):0.);
  outSig[0] =  _Mtr_1 ;
  outSig[1] =  _Wdtr_1 ;
  outSig[2] =  __dW_in_dtr_1 ;
  outSig[3] =  __dTw_Wdt_dtr_1 ;


}

EXPORT32 void PASCAL EXPORT OrificeSS(DOUBLE param[], long *runCount)
{ simInit( OrificeDeriv, 0, 0, 0, 0, 0, 10, 0.01, 0);
  vsmEvent(VSE_PRE_SIM_START,0,0);
}

EXPORT32 void PASCAL EXPORT OrificeSE(DOUBLE param[], long *runCount)
{
}
