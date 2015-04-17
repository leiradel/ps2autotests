#ifndef PS2AUTOTESTS_VU_ASSEMBLE_BLOCK_H
#define PS2AUTOTESTS_VU_ASSEMBLE_BLOCK_H

#include "types.h"

namespace VU {

class Block {
public:
	Block(LIW *addr);

	void Wr(LowerOp l);
	void Wr(UpperOp u);
	void Wr(UpperOp u, LowerOp l);
	void WrImm(float imm);
	void WrImm(u32 imm);
	void WrImm(s32 imm);
	void WrImm(UpperOp u, float imm);
	void WrImm(UpperOp u, u32 imm);
	void WrImm(UpperOp u, s32 imm);

	Label L();
	void L(Label &l);

	// For branches, the delay slot is specified directly.
	// This is just to prevent accidents.

	Label B(UpperOp u, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void B(UpperOp u, Label l, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void B(Label l, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return B(UpperOp(), l, delayu, delayl);
	}

	Label BAL(UpperOp u, Reg t = VI_LR, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void BAL(UpperOp u, Label l, Reg t = VI_LR, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void BAL(Label l, Reg t = VI_LR, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return BAL(UpperOp(), l, t, delayu, delayl);
	}

	Label IBEQ(UpperOp u, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBEQ(UpperOp u, Label l, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBEQ(Label l, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBEQ(UpperOp(), l, t, s, delayu, delayl);
	}

	Label IBGEZ(UpperOp u, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBGEZ(UpperOp u, Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBGEZ(Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBGEZ(UpperOp(), l, s, delayu, delayl);
	}

	Label IBGTZ(UpperOp u, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBGTZ(UpperOp u, Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBGTZ(Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBGTZ(UpperOp(), l, s, delayu, delayl);
	}

	Label IBLEZ(UpperOp u, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBLEZ(UpperOp u, Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBLEZ(Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBLEZ(UpperOp(), l, s, delayu, delayl);
	}

	Label IBLTZ(UpperOp u, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBLTZ(UpperOp u, Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBLTZ(Label l, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBLTZ(UpperOp(), l, s, delayu, delayl);
	}

	Label IBNE(UpperOp u, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBNE(UpperOp u, Label l, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp());
	void IBNE(Label l, Reg t, Reg s, UpperOp delayu = UpperOp(), LowerOp delayl = LowerOp()) {
		return IBNE(UpperOp(), l, t, s, delayu, delayl);
	}

	void SafeExit();

protected:
	void FixupLabel(Label l);
	LowerOp EncodeFixupLower(Label l, s16 dist);
	Label DeferBranch(BranchType type, UpperOp u, Reg s, Reg t, UpperOp delayu, LowerOp delayl);
	void DoBranch(BranchType type, UpperOp u, Label l, Reg s, Reg t, UpperOp delayu, LowerOp delayl);

	LIW *start_;
	LIW *addr_;
};

}

#endif
