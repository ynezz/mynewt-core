/**
 * Copyright (c) 2017, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_GLUE_H__
#define NRFX_GLUE_H__

#include <assert.h>
#include "os/mynewt.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_glue nrfx_glue.h
 * @{
 * @ingroup nrfx
 *
 * @brief This file contains macros that should be implemented according to
 *        the needs of the host environment into which @em nrfx is integrated.
 */

/**
 * @brief Macro for placing a runtime assertion.
 *
 * @param expression  Expression to evaluate.
 */
#define NRFX_ASSERT(expression) assert(expression);

/**
 * @brief Macro for placing a compile time assertion.
 *
 * @param expression  Expression to evaluate.
 */
#define NRFX_STATIC_ASSERT(expression) STATIC_ASSERT(expression);

/**
 * @brief Macro for setting the priority of a specific IRQ.
 * @param irq_number  IRQ number.
 * @param priority    Priority to set.
 */
#define NRFX_IRQ_PRIORITY_SET(irq_number, priority) NVIC_SetPriority(irq_number, priority);

/**
 * @brief Macro for enabling a specific IRQ.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_ENABLE(irq_number) NVIC_EnableIRQ(irq_number);

/**
 * @brief Macro for checking if a specific IRQ is enabled.
 *
 * @param irq_number  IRQ number.
 *
 * @retval true  If the IRQ is enabled.
 * @retval false Otherwise.
 */
#define NRFX_IRQ_IS_ENABLED(irq_number) (NVIC_GetEnableIRQ(irq_number) == 1);

/**
 * @brief Macro for disabling a specific IRQ.
 *
 * @param irq_number  IRQ number.
 */
#define NRFX_IRQ_DISABLE(irq_number) NVIC_DisableIRQ(irq_number);


/**
 * @brief Macro for entering into a critical section.
 */
static os_sr_t sr_from_macro __attribute__((unused));

#define NRFX_CRITICAL_SECTION_ENTER() OS_ENTER_CRITICAL(sr_from_macro);

/**
 * @brief Macro for exiting from a critical section.
 */
#define NRFX_CRITICAL_SECTION_EXIT() OS_EXIT_CRITICAL(sr_from_macro);

/**
 * @brief When set to a non-zero value, this macro specifies that the
 *        @ref nrfx_error_codes and the @ref nrfx_err_t type itself are defined
 *        in a customized way and the default definitions from @c <nrfx_error.h>
 *        should not be used.
 */
#define NRFX_CUSTOM_ERROR_CODES 0

/**
 * @brief Bitmask defining PPI channels reserved to be used outside of nrfx.
 */
#define NRFX_PPI_CHANNELS_USED  0

/**
 * @brief Bitmask defining PPI groups reserved to be used outside of nrfx.
 */
#define NRFX_PPI_GROUPS_USED    0

/**
 * @brief Bitmask defining SWI instances reserved to be used outside of nrfx.
 */
#define NRFX_SWI_USED           0

/**
 * @brief Bitmask defining TIMER instances reserved to be used outside of nrfx.
 */
#define NRFX_TIMERS_USED        0

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NRFX_GLUE_H__
