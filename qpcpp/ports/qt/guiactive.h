//****************************************************************************
// Product: QP/C++ port to Qt
// Last Updated for Version: QP 5.1.1/Qt 5.1.1
// Date of the Last Update:  Nov 05, 2013
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) 2002-2013 Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//
// Contact information:
// Quantum Leaps Web sites: http://www.quantum-leaps.com
//                          http://www.state-machine.com
// e-mail:                  info@quantum-leaps.com
//****************************************************************************
#ifndef guiactive_h
#define guiactive_h

namespace QP {

//............................................................................
class GuiQActive : public QActive {
public:
    GuiQActive(QStateHandler const initial) : QActive(initial) {}
    virtual void start(uint8_t const prio,
                       QEvt const *qSto[], uint32_t const qLen,
                       void * const stkSto, uint32_t const stkSize,
                       QEvt const * const ie);
#ifndef Q_SPY
    virtual bool post(QEvt const * const e, uint16_t const margin);
#else
    virtual bool post(QEvt const * const e, uint16_t const margin,
                      void const * const sender);
#endif
    virtual void postLIFO(QEvt const * const e);
};

//............................................................................
class GuiQMActive : public QMActive {
public:
    GuiQMActive(QStateHandler const initial) : QMActive(initial) {}
    virtual void start(uint8_t const prio,
                       QEvt const *qSto[], uint32_t const qLen,
                       void * const stkSto, uint32_t const stkSize,
                       QEvt const * const ie);
#ifndef Q_SPY
    virtual bool post(QEvt const * const e, uint16_t const margin);
#else
    virtual bool post(QEvt const * const e, uint16_t const margin,
                      void const * const sender);
#endif
    virtual void postLIFO(QEvt const * const e);
};

}                                                              // namespace QP

#endif                                                          // guiactive_h
