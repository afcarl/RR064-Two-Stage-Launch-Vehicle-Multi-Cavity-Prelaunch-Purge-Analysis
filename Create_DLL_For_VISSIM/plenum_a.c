/*** VisSim Automatic Code Generator ***/
/*  Output for D:\VISSIM30\multi_cavity\vent_g4c1_mod_e1_v30.vsm at Thu Feb 12 12:44:24 1998 */


#include "math.h"
#include "cgen.h"
#include "cgendll.h"
CGDOUBLE derivIn[]={
0,0,0
};
CGDOUBLE integOut0[]={
0,0,0
};
CGDOUBLE integOut1[]={
0,0,0
};
CGDOUBLE integIC[]={
0,0,0
};
CGDOUBLE *integOut=integOut0;
INTEG_LIMIT integLimit[3];

extern CGDOUBLE T,Zed;

CGDOUBLE _dWtr_12126;
CGDOUBLE _dTw_Wdt_12126;
CGDOUBLE _Tt_vol_i_12126;
CGDOUBLE _Ttr_12126;
CGDOUBLE _Tt_vol_12126;
CGDOUBLE _Wt_vol_i_12126;
CGDOUBLE _Wtr_12126;
CGDOUBLE _Wt_vol_12126;
CGDOUBLE _dW_in_12126;
CGDOUBLE _dTv_12126;
CGDOUBLE _pt_vol_i_12126;
CGDOUBLE _Ptr_12126;
CGDOUBLE _pt_vol_12126;
CGDOUBLE _dpt_12126;
CGDOUBLE _c_p_wT_12126;
DLL_SIG_DECL(8,4)
DLL_FUNC_DEF(Plenum)

void PlenumDeriv()
{
  _dWtr_12126 =  inSig[3] ;
  _dTw_Wdt_12126 =  inSig[5] ;
  _Tt_vol_i_12126 =  inSig[2] ;
  _Ttr_12126 =  integOut[1] ;
  _Tt_vol_12126 = ( _Tt_vol_i_12126 + _Ttr_12126 );
  _Wt_vol_i_12126 =  inSig[0] ;
  _Wtr_12126 =  integOut[0] ;
  _Wt_vol_12126 = ( _Wt_vol_i_12126 + _Wtr_12126 );
  _dW_in_12126 =  inSig[4] ;
  _dTv_12126 = (((((((1.* _dTw_Wdt_12126 * sim.timeStep )+( _Tt_vol_12126 * _Wt_vol_12126 )))/(( _Wt_vol_12126 +( _dW_in_12126 *
	 sim.timeStep ))))- _Tt_vol_12126 ))/( sim.timeStep ));
  _pt_vol_i_12126 =  inSig[1] ;
  _Ptr_12126 =  integOut[2] ;
  _pt_vol_12126 = ( _pt_vol_i_12126 + _Ptr_12126 );
  _dpt_12126 = ( _pt_vol_12126 *((( _dWtr_12126 )/( _Wt_vol_12126 ))+(( _dTv_12126 )/( _Tt_vol_12126 ))));
  _c_p_wT_12126 = (((( _pt_vol_12126 )/( _Tt_vol_12126 )))/( _Wt_vol_12126 ));
  outSig[0] =  _Wt_vol_12126 ;
  outSig[1] =  _pt_vol_12126 ;
  outSig[2] =  _Tt_vol_12126 ;
  outSig[3] =  _c_p_wT_12126 ;

  derivIn[0] =  _dWtr_12126 ;
  derivIn[1] =  _dTv_12126 ;
  derivIn[2] =  _dpt_12126 ;

}

void limitIntegOutput()
{

}


EXPORT32 void PASCAL EXPORT PlenumSS(DOUBLE param[], long *runCount)
{ simInit( PlenumDeriv, 3, 0, 0, 0, -65, -1, 0.0001, 2);
  vsmEvent(VSE_PRE_SIM_START,0,0);
}

EXPORT32 void PASCAL EXPORT PlenumSE(DOUBLE param[], long *runCount)
{
}
