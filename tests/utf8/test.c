#include "qcommon/q_shared.h"
#undef NDEBUG
#include <assert.h>
#include <stdio.h>
static void check(const char *text, unsigned int cp, int expected) {
 int n=0; assert(Q_UTF8_ReadCharFromString(text,&n)==cp); assert(n==expected);
}
int main(void) {
 unsigned int cp; char text[5]; int n;
 check("A",65,1); check("\xD0\xAF",0x42F,2); check("\xE4\xB8\xAD",0x4E2D,3); check("\xF0\x9F\x98\x80",0x1F600,4);
 check("\xC0\xAF",0xC0,1); check("\xED\xA0\x80",0xED,1); check("\xF4\x90\x80\x80",0xF4,1);
 check("\xE2",0xE2,1); check("\xE2\x82",0xE2,1); check("\xF0\x9F\x98",0xF0,1); check("\xFF",255,1);
 for(cp=1;cp<=0x10FFFF;cp++) {
  if(cp>=0xD800 && cp<=0xDFFF) continue;
  n=Q_UTF8_Encode(cp,text); assert(n>=1&&n<=4); text[n]=0; check(text,cp,n);
 }
 n=Q_UTF8_Encode(0xD800,text);text[n]=0;check(text,0xFFFD,3);
 n=Q_UTF8_Encode(0x110000,text);text[n]=0;check(text,0xFFFD,3);
 assert(Q_UTF8_Strlen("A\xD0\xAF\xF0\x9F\x98\x80")==3);
 puts("UTF-8 tests passed: all Unicode scalar values round-trip; invalid and truncated sequences preserve byte fallback.");
 return 0;
}
void QDECL Com_Printf(const char *fmt, ...) { (void)fmt; }
void QDECL Com_Error(int code, const char *fmt, ...) { (void)code; (void)fmt; abort(); }
