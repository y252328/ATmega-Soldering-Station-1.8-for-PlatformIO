#include "bit_map.h"

const unsigned char *C_table[] = {c1, c2, c3, Lightning, c5, c6, c7};
#if LANG_JP_State
const unsigned char *Ico_table[] = {
  Set0, Set1, Set2, Set3, Set4, Set5, Set19, Set6, Lock, Set_LANG, QRC, Set7,
  Set8, Set9, Set0, Set10, Set12, Set7,
  Set0, Set11, Set14, Save,
  Set11, Set13, Set14, Save,
  Set15, Set16,
  Set17, Set18, //5
  Set5_1, Set5,
  c_NO, Set7,
  Lang_CN, Lang_EN, Lang_JP, //8
  Set4, Set4F, Save,
};
#else
const unsigned char *Ico_table[] = {
  Set0, Set1, Set2, Set3, Set4, Set5, Set19, Set6, Lock, Set_LANG, QRC, Set7,
  Set8, Set9, Set0, Set10, Set12, Set7,
  Set0, Set11, Set14, Save,
  Set11, Set13, Set14, Save,
  Set15, Set16,
  Set17, Set18, //5
  Set5_1, Set5,
  c_NO, Set7,
  Lang_CN, Lang_EN,c_NO, //8
  Set4, Set4F, Save,
};
#endif
byte MenuLevel = 0; //菜单层级
