#ifndef _ASM_X86_MSHYPER_H
#define _ASM_X86_MSHYPER_H

#include <linux/types.h>
#include <linux/interrupt.h>
#include <asm/hyperv.h>

struct ms_hyperv_info {
	u32 features;
	u32 misc_features;
	u32 hints;
};

extern struct ms_hyperv_info ms_hyperv;

#define hv_get_vp_index(index) rdmsrl(HV_X64_MSR_VP_INDEX, index)

void hyperv_callback_vector(void);
#ifdef CONFIG_TRACING
#define trace_hyperv_callback_vector hyperv_callback_vector
#endif
void hyperv_vector_handler(struct pt_regs *regs);
void hv_setup_vmbus_irq(void (*handler)(void));
void hv_remove_vmbus_irq(void);

void hv_setup_kexec_handler(void (*handler)(void));
void hv_remove_kexec_handler(void);
void hv_setup_crash_handler(void (*handler)(struct pt_regs *regs));
void hv_remove_crash_handler(void);

#define hv_get_synint_state(int_num, val) rdmsrl(int_num, val)
#define hv_set_synint_state(int_num, val) wrmsrl(int_num, val)

#define hv_get_simp(val) rdmsrl(HV_X64_MSR_SIMP, val)
#define hv_set_simp(val) wrmsrl(HV_X64_MSR_SIMP, val)

#define hv_get_siefp(val) rdmsrl(HV_X64_MSR_SIEFP, val)
#define hv_set_siefp(val) wrmsrl(HV_X64_MSR_SIEFP, val)
#define hv_get_synic_state(val) rdmsrl(HV_X64_MSR_SCONTROL, val)
#define hv_set_synic_state(val) wrmsrl(HV_X64_MSR_SCONTROL, val)

#endif
