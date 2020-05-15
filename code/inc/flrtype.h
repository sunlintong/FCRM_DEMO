/* file flrtype.h                                                           */

/****************************************************************************/
/****************************************************************************/
/*                                                                          */ 
/*                                                                          */ 
/*                    FLR PACKAGE TYPE DEFINITION                           */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/

//
// MODIFICATIONS:
//
//

#ifndef FLRTYPE_H
#define FLRTYPE_H

#include "consttype.h"
#include "flrconst.h"


typedef struct {
                word16 chaflrcod ; /* Failure code                     */
                word16 stt[4];     /* State_val[i-1] is the state      */
                                   /* value, when i signals of an      */
                                   /* element, are failed.             */
			} flr_fcssttrec ;     /* FCS state table type */


typedef struct {
                 word16 flrcod ;   /* Failure code                     */
                 word16   mux ;    /* Analog to digital mux number     */

			} flr_anainpsigrec ;  /* Analog input signals table type */


typedef struct {
                 word16 flrcod ;   /* Failure code                     */
			} flr_disinpsigrec ;  /* Discrete input signals table type */

typedef struct {
          word32  frserrtim;          /* time of first error             */
          word32  frsrvrtim;          /* recovery time                   */
          boolean frserrtimexs;       /* flag time of first error exist  */
          boolean frsrvrtimexs;       /* flag recovery time exist        */
			} flr_muberriforec ; 

#endif
