#include"pin/ins.h"

bool op_is_branch(LA_OPCODE opc)
{
    return (LISA_BEQZ <= opc && opc <= LISA_BGEU);
}

bool op_is_direct_branch(LA_OPCODE opc)
{
    return ((LISA_BEQZ <= opc && opc <= LISA_BCNEZ) || (LISA_B <= opc && opc <= LISA_BGEU));
}

bool op_is_indirect_branch(LA_OPCODE opc)
{
    return ((opc == LISA_JIRL) || (LISA_JISCR0 <= opc && opc <= LISA_JISCR1));
}

bool op_is_condition_branch(LA_OPCODE opc)
{
    return ((LISA_BEQZ <= opc && opc <= LISA_BCNEZ)
            || (LISA_BEQ <= opc && opc <= LISA_BGEU));
}

bool op_is_float_branch(LA_OPCODE opc)
{
    return (LISA_BCEQZ == opc || LISA_BCNEZ == opc);
}

bool op_is_syscall(LA_OPCODE opc)
{
    return (opc == LISA_SYSCALL);
}

bool op_is_ldst(LA_OPCODE opc)
{
    return (op_is_load(opc) || op_is_store(opc));
}

bool op_is_load(LA_OPCODE opc)
{
    switch (opc) {
    case LISA_LL_W:
    case LISA_LL_D:
    case LISA_LDPTR_W:
    case LISA_LDPTR_D:
    case LISA_LD_B:
    case LISA_LD_H:
    case LISA_LD_W:
    case LISA_LD_D:
    case LISA_LD_BU:
    case LISA_LD_HU:
    case LISA_LD_WU:
    case LISA_PRELD:
    case LISA_FLD_S:
    case LISA_FLD_D:
    case LISA_VLD:
    case LISA_XVLD:
    case LISA_LDL_W:
    case LISA_LDR_W:
    case LISA_LDL_D:
    case LISA_LDR_D:
    case LISA_VLDREPL_D:
    case LISA_VLDREPL_W:
    case LISA_VLDREPL_H:
    case LISA_VLDREPL_B:
    case LISA_XVLDREPL_D:
    case LISA_XVLDREPL_W:
    case LISA_XVLDREPL_H:
    case LISA_XVLDREPL_B:
    case LISA_LDX_B:
    case LISA_LDX_H:
    case LISA_LDX_W:
    case LISA_LDX_D:
    case LISA_LDX_BU:
    case LISA_LDX_HU:
    case LISA_LDX_WU:
    case LISA_PRELDX:
    case LISA_FLDX_S:
    case LISA_FLDX_D:
    case LISA_VLDX:
    case LISA_XVLDX:
    case LISA_FLDGT_S:
    case LISA_FLDGT_D:
    case LISA_FLDLE_S:
    case LISA_FLDLE_D:
    case LISA_LDGT_B:
    case LISA_LDGT_H:
    case LISA_LDGT_W:
    case LISA_LDGT_D:
    case LISA_LDLE_B:
    case LISA_LDLE_H:
    case LISA_LDLE_W:
    case LISA_LDLE_D:
        return true;
    default:
        return false;
    }
}

bool op_is_store(LA_OPCODE opc)
{
    switch (opc) {
    case LISA_SC_W:
    case LISA_SC_D:
    case LISA_STPTR_W:
    case LISA_STPTR_D:
    case LISA_ST_B:
    case LISA_ST_H:
    case LISA_ST_W:
    case LISA_ST_D:
    case LISA_FST_S:
    case LISA_FST_D:
    case LISA_VST:
    case LISA_XVST:
    case LISA_STL_W:
    case LISA_STR_W:
    case LISA_STL_D:
    case LISA_STR_D:
    case LISA_VSTELM_D:
    case LISA_VSTELM_W:
    case LISA_VSTELM_H:
    case LISA_VSTELM_B:
    case LISA_XVSTELM_D:
    case LISA_XVSTELM_W:
    case LISA_XVSTELM_H:
    case LISA_XVSTELM_B:
    case LISA_STX_B:
    case LISA_STX_H:
    case LISA_STX_W:
    case LISA_STX_D:
    case LISA_FSTX_S:
    case LISA_FSTX_D:
    case LISA_VSTX:
    case LISA_XVSTX:
    case LISA_FSTGT_S:
    case LISA_FSTGT_D:
    case LISA_FSTLE_S:
    case LISA_FSTLE_D:
    case LISA_STGT_B:
    case LISA_STGT_H:
    case LISA_STGT_W:
    case LISA_STGT_D:
    case LISA_STLE_B:
    case LISA_STLE_H:
    case LISA_STLE_W:
    case LISA_STLE_D:
        return true;
    default:
        return false;
    }
}

bool op_is_float_load(LA_OPCODE opc)
{
    switch (opc) {
    case LISA_FLD_S:
    case LISA_FLD_D:
    case LISA_VLD:
    case LISA_XVLD:
    case LISA_VLDREPL_D:
    case LISA_VLDREPL_W:
    case LISA_VLDREPL_H:
    case LISA_VLDREPL_B:
    case LISA_XVLDREPL_D:
    case LISA_XVLDREPL_W:
    case LISA_XVLDREPL_H:
    case LISA_XVLDREPL_B:
    case LISA_FLDX_S:
    case LISA_FLDX_D:
    case LISA_VLDX:
    case LISA_XVLDX:
    case LISA_FLDGT_S:
    case LISA_FLDGT_D:
    case LISA_FLDLE_S:
    case LISA_FLDLE_D:
        return true;
    default:
        return false;
    }
}

bool op_is_float_store(LA_OPCODE opc)
{
    switch (opc) {
    case LISA_FST_S:
    case LISA_FST_D:
    case LISA_VST:
    case LISA_XVST:
    case LISA_VSTELM_D:
    case LISA_VSTELM_W:
    case LISA_VSTELM_H:
    case LISA_VSTELM_B:
    case LISA_XVSTELM_D:
    case LISA_XVSTELM_W:
    case LISA_XVSTELM_H:
    case LISA_XVSTELM_B:
    case LISA_FSTX_S:
    case LISA_FSTX_D:
    case LISA_VSTX:
    case LISA_XVSTX:
    case LISA_FSTGT_S:
    case LISA_FSTGT_D:
    case LISA_FSTLE_S:
    case LISA_FSTLE_D:
        return true;
    default:
        return false;
    }
}

bool op_is_am(LA_OPCODE opc)
{
    switch (opc) {
    case LISA_AMSWAP_W:
    case LISA_AMSWAP_D:
    case LISA_AMADD_W:
    case LISA_AMADD_D:
    case LISA_AMAND_W:
    case LISA_AMAND_D:
    case LISA_AMOR_W:
    case LISA_AMOR_D:
    case LISA_AMXOR_W:
    case LISA_AMXOR_D:
    case LISA_AMMAX_W:
    case LISA_AMMAX_D:
    case LISA_AMMIN_W:
    case LISA_AMMIN_D:
    case LISA_AMMAX_WU:
    case LISA_AMMAX_DU:
    case LISA_AMMIN_WU:
    case LISA_AMMIN_DU:
    case LISA_AMSWAP_DB_W:
    case LISA_AMSWAP_DB_D:
    case LISA_AMADD_DB_W:
    case LISA_AMADD_DB_D:
    case LISA_AMAND_DB_W:
    case LISA_AMAND_DB_D:
    case LISA_AMOR_DB_W:
    case LISA_AMOR_DB_D:
    case LISA_AMXOR_DB_W:
    case LISA_AMXOR_DB_D:
    case LISA_AMMAX_DB_W:
    case LISA_AMMAX_DB_D:
    case LISA_AMMIN_DB_W:
    case LISA_AMMIN_DB_D:
    case LISA_AMMAX_DB_WU:
    case LISA_AMMAX_DB_DU:
    case LISA_AMMIN_DB_WU:
    case LISA_AMMIN_DB_DU:
        return true;
    default:
        return false;
    }
}

bool op_is_ll(LA_OPCODE opc)
{
    return (opc == LISA_LL_W || opc == LISA_LL_D);
}

bool op_is_sc(LA_OPCODE opc)
{
    return (opc == LISA_SC_W || opc == LISA_SC_D);
}
