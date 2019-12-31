/*.$file${.::qhsmtst.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: qhsmtst.qm
* File:  ${.::qhsmtst.c}
*
* This code has been generated by QM 4.6.0 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${.::qhsmtst.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpn.h"
#include "bsp.h"
#include "qhsmtst.h"

/*.$declare${HSMs::QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${HSMs::QHsmTst} ........................................................*/
typedef struct QHsmTst {
/* protected: */
    QHsm super;

/* private: */
    uint8_t foo;

/* private state histories */
    QStateHandler hist_s1;
} QHsmTst;

/* protected: */
static QState QHsmTst_initial(QHsmTst * const me);
static QState QHsmTst_s(QHsmTst * const me);
static QState QHsmTst_s1(QHsmTst * const me);
static QState QHsmTst_s11(QHsmTst * const me);
static QState QHsmTst_s2(QHsmTst * const me);
static QState QHsmTst_s21(QHsmTst * const me);
static QState QHsmTst_s211(QHsmTst * const me);
/*.$enddecl${HSMs::QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

static QHsmTst l_hsmtst; /* the only instance of the QHsmTst class */

/* global-scope definitions ---------------------------------------*/
QHsm * const the_hsm = (QHsm *)&l_hsmtst; /* the opaque pointer */

/*.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*. Check for the minimum required QP version */
#if (QP_VERSION < 650U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpn version 6.5.0 or higher required
#endif
/*.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${HSMs::QHsmTst_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${HSMs::QHsmTst_ctor} ...................................................*/
void QHsmTst_ctor(void) {
    QHsmTst *me = &l_hsmtst;
    QHsm_ctor(&me->super, Q_STATE_CAST(&QHsmTst_initial));
}
/*.$enddef${HSMs::QHsmTst_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${HSMs::QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${HSMs::QHsmTst} ........................................................*/
/*.${HSMs::QHsmTst::SM} ....................................................*/
static QState QHsmTst_initial(QHsmTst * const me) {
    /*.${HSMs::QHsmTst::SM::initial} */
    me->foo = 0U;
    BSP_display("top-INIT;");
    /* state history attributes */
    /* state history attributes */
    me->hist_s1 = Q_STATE_CAST(&QHsmTst_s11);
    return Q_TRAN(&QHsmTst_s2);
}
/*.${HSMs::QHsmTst::SM::s} .................................................*/
static QState QHsmTst_s(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s} */
        case Q_ENTRY_SIG: {
            BSP_display("s-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s} */
        case Q_EXIT_SIG: {
            BSP_display("s-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::initial} */
        case Q_INIT_SIG: {
            BSP_display("s-INIT;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::I} */
        case I_SIG: {
            /*.${HSMs::QHsmTst::SM::s::I::[me->foo]} */
            if (me->foo) {
                me->foo = 0U;
                BSP_display("s-I;");
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::E} */
        case E_SIG: {
            BSP_display("s-E;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::TERMINATE} */
        case TERMINATE_SIG: {
            BSP_exit();
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.${HSMs::QHsmTst::SM::s::s1} .............................................*/
static QState QHsmTst_s1(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s::s1} */
        case Q_ENTRY_SIG: {
            BSP_display("s1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1} */
        case Q_EXIT_SIG: {
            BSP_display("s1-EXIT;");
            /* save deep history */
            me->hist_s1 = QHsm_state(me);
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::initial} */
        case Q_INIT_SIG: {
            BSP_display("s1-INIT;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::I} */
        case I_SIG: {
            BSP_display("s1-I;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::D} */
        case D_SIG: {
            /*.${HSMs::QHsmTst::SM::s::s1::D::[!me->foo]} */
            if (!me->foo) {
                me->foo = 1U;
                BSP_display("s1-D;");
                status_ = Q_TRAN(&QHsmTst_s);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::A} */
        case A_SIG: {
            BSP_display("s1-A;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::B} */
        case B_SIG: {
            BSP_display("s1-B;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::F} */
        case F_SIG: {
            BSP_display("s1-F;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::C} */
        case C_SIG: {
            BSP_display("s1-C;");
            status_ = Q_TRAN(&QHsmTst_s2);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s);
            break;
        }
    }
    return status_;
}
/*.${HSMs::QHsmTst::SM::s::s1::s11} ........................................*/
static QState QHsmTst_s11(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s::s1::s11} */
        case Q_ENTRY_SIG: {
            BSP_display("s11-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::s11} */
        case Q_EXIT_SIG: {
            BSP_display("s11-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::s11::H} */
        case H_SIG: {
            BSP_display("s11-H;");
            status_ = Q_TRAN(&QHsmTst_s);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::s11::D} */
        case D_SIG: {
            /*.${HSMs::QHsmTst::SM::s::s1::s11::D::[me->foo]} */
            if (me->foo) {
                me->foo = 0U;
                BSP_display("s11-D;");
                status_ = Q_TRAN(&QHsmTst_s1);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s1::s11::G} */
        case G_SIG: {
            BSP_display("s11-G;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s1);
            break;
        }
    }
    return status_;
}
/*.${HSMs::QHsmTst::SM::s::s2} .............................................*/
static QState QHsmTst_s2(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s::s2} */
        case Q_ENTRY_SIG: {
            BSP_display("s2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2} */
        case Q_EXIT_SIG: {
            BSP_display("s2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::initial} */
        case Q_INIT_SIG: {
            BSP_display("s2-INIT;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::I} */
        case I_SIG: {
            /*.${HSMs::QHsmTst::SM::s::s2::I::[!me->foo]} */
            if (!me->foo) {
                me->foo = 1U;
                BSP_display("s2-I;");
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::F} */
        case F_SIG: {
            BSP_display("s2-F;");
            status_ = Q_TRAN_HIST(me->hist_s1);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::C} */
        case C_SIG: {
            BSP_display("s2-C;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s);
            break;
        }
    }
    return status_;
}
/*.${HSMs::QHsmTst::SM::s::s2::s21} ........................................*/
static QState QHsmTst_s21(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s::s2::s21} */
        case Q_ENTRY_SIG: {
            BSP_display("s21-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21} */
        case Q_EXIT_SIG: {
            BSP_display("s21-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::initial} */
        case Q_INIT_SIG: {
            BSP_display("s21-INIT;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::G} */
        case G_SIG: {
            BSP_display("s21-G;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::A} */
        case A_SIG: {
            BSP_display("s21-A;");
            status_ = Q_TRAN(&QHsmTst_s21);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::B} */
        case B_SIG: {
            BSP_display("s21-B;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s2);
            break;
        }
    }
    return status_;
}
/*.${HSMs::QHsmTst::SM::s::s2::s21::s211} ..................................*/
static QState QHsmTst_s211(QHsmTst * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${HSMs::QHsmTst::SM::s::s2::s21::s211} */
        case Q_ENTRY_SIG: {
            BSP_display("s211-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::s211} */
        case Q_EXIT_SIG: {
            BSP_display("s211-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::s211::H} */
        case H_SIG: {
            BSP_display("s211-H;");
            status_ = Q_TRAN(&QHsmTst_s);
            break;
        }
        /*.${HSMs::QHsmTst::SM::s::s2::s21::s211::D} */
        case D_SIG: {
            BSP_display("s211-D;");
            status_ = Q_TRAN(&QHsmTst_s21);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s21);
            break;
        }
    }
    return status_;
}
/*.$enddef${HSMs::QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
