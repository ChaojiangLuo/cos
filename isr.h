#ifndef _ISR_H
#define _ISR_H 

#include "common.h"
#include "gdt.h"

#define IRQ0 32 // PIT
#define IRQ1 33 // KBD
#define IRQ2 34 // slave
#define IRQ3 35 // serial2
#define IRQ4 36 // serial1
#define IRQ5 37 // LPT2
#define IRQ6 38 // floppy
#define IRQ7 39 // LPT1

#define IRQ8  40 // RTC
#define IRQ9  41 // IRQ2
#define IRQ10 42 // reserve
#define IRQ11 43 // reserve
#define IRQ12 44 // PS/2 mouse
#define IRQ13 45 // FPU
#define IRQ14 46 // ATA HD1
#define IRQ15 47 // ATA HD2

typedef struct registers_s {
    u32 ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 isrno, errcode;
    // Pushed by the processor automatically.
    u32 eip, cs, eflags;
    u32 useresp, ss;  // exists only when PL switched
} __attribute__((packed)) registers_t;

void isr_handler(registers_t regs);
void irq_handler(registers_t regs);

typedef void (*interrupt_handler)(registers_t regs);
void register_isr_handler(int isr, interrupt_handler cb);

#endif
