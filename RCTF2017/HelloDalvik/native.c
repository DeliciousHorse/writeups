signed int __cdecl Java_com_rctf_hellodalvik_MainActivity_stringFromJNI(JNIEnv *a1)
{
  int v1; // ecx@1
  unsigned __int32 page_size; // ebp@3
  unsigned int classesDexAddr; // edi@3
  int v4; // ecx@3
  int dexFileInMemory; // edi@5
  int v6; // eax@6
  void *v7; // eax@7
  signed int result; // eax@8
  volatile signed __int32 *v9; // ecx@10
  signed __int32 v10; // edx@11
  char v11; // [sp+18h] [bp-234h]@3
  int v12; // [sp+20h] [bp-22Ch]@1
  char math_method_1; // [sp+28h] [bp-224h]@3
  char v14; // [sp+29h] [bp-223h]@3
  char v15; // [sp+2Ah] [bp-222h]@3
  char v16; // [sp+2Bh] [bp-221h]@3
  char v17; // [sp+2Ch] [bp-220h]@3
  char v18; // [sp+2Dh] [bp-21Fh]@3
  char v19; // [sp+2Eh] [bp-21Eh]@3
  char v20; // [sp+2Fh] [bp-21Dh]@3
  char v21; // [sp+30h] [bp-21Ch]@3
  char v22; // [sp+31h] [bp-21Bh]@3
  char v23; // [sp+32h] [bp-21Ah]@3
  char v24; // [sp+33h] [bp-219h]@3
  char v25; // [sp+34h] [bp-218h]@3
  char mathMethod_class_path_[33]; // [sp+A8h] [bp-1A4h]@4
  char v27; // [sp+C9h] [bp-183h]@5
  char math_method_4; // [sp+128h] [bp-124h]@3
  char v29; // [sp+129h] [bp-123h]@3
  char v30; // [sp+12Ah] [bp-122h]@3
  char v31; // [sp+12Bh] [bp-121h]@3
  char v32; // [sp+12Ch] [bp-120h]@3
  char v33; // [sp+12Dh] [bp-11Fh]@3
  char v34; // [sp+12Eh] [bp-11Eh]@3
  char v35; // [sp+12Fh] [bp-11Dh]@3
  char v36; // [sp+130h] [bp-11Ch]@3
  char v37; // [sp+131h] [bp-11Bh]@3
  char v38; // [sp+132h] [bp-11Ah]@3
  char v39; // [sp+133h] [bp-119h]@3
  char v40; // [sp+134h] [bp-118h]@3
  char needle[48]; // [sp+1A8h] [bp-A4h]@2
  char v42; // [sp+1D8h] [bp-74h]@3
  int v43; // [sp+228h] [bp-24h]@6
  int v44; // [sp+22Ch] [bp-20h]@6
  int v45; // [sp+238h] [bp-14h]@1

  v45 = *MK_FP(__GS__, 20);
  sub_7980((int)&v12, "Hello from C++");
  v1 = 0;
  do
  {
    needle[v1] = dalvik_cache_path[v1] + 0x2B;  // /data/dalvik-cache/data@app@com.rctf.hellodalvik
    ++v1;
  }
  while ( v1 != 47 );
  v42 = 0;
  needle[47] = dalvik_cache_path[47] + 0x2B;
  ((void (__cdecl *)(JNIEnv *, int, char *))(*a1)->NewStringUTF)(a1, v12, &v11);
  math_method_1 = MathMethod1[0] + 0x20;        // MathMethod_1 
  v14 = MathMethod1[1] + 32;
  v15 = MathMethod1[2] + 32;
  v16 = MathMethod1[3] + 32;
  v17 = MathMethod1[4] + 32;
  v18 = MathMethod1[5] + 32;
  v19 = MathMethod1[6] + 32;
  v20 = MathMethod1[7] + 32;
  v21 = MathMethod1[8] + 32;
  v22 = MathMethod1[9] + 32;
  v23 = MathMethod1[10] + 32;
  v25 = 0;
  v24 = MathMethod1[11] + 32;
  page_size = sysconf(0x27);                    // I guess its page size
  classesDexAddr = (unsigned int)getClassesDexLoadAddr(needle);
  math_method_4 = MathMethod4[0] + 0x1C;        // MathMethod_4
  v29 = MathMethod4[1] + 28;
  v30 = MathMethod4[2] + 28;
  v31 = MathMethod4[3] + 28;
  v32 = MathMethod4[4] + 28;
  v33 = MathMethod4[5] + 28;
  v34 = MathMethod4[6] + 28;
  v35 = MathMethod4[7] + 28;
  v36 = MathMethod4[8] + 28;
  v37 = MathMethod4[9] + 28;
  v38 = MathMethod4[10] + 28;
  v40 = 0;
  v39 = MathMethod4[11] + 28;
  v4 = 0;
  do
  {
    mathMethod_class_path_[v4] = MathMethod_class_path[v4] + 0x11;
    ++v4;
  }
  while ( v4 != 32 );
  v27 = 0;
  mathMethod_class_path_[32] = MathMethod_class_path[32] + 0x11;// Lcom/rctf/hellodalvik/MathMethod;
                                                // 
  dexFileInMemory = classesDexAddr + 40 - classesDexAddr % page_size;
  do
  {
    v44 = '530';
    v43 = '\nxed';
    v6 = memcmp((const void *)(dexFileInMemory - page_size), &v43, 8u);// find DEX header
    dexFileInMemory -= page_size;
  }
  while ( v6 );
  patch(page_size, dexFileInMemory, &math_method_4, mathMethod_class_path_, 1);// method_4 -> add
  patch(page_size, dexFileInMemory, &math_method_1, mathMethod_class_path_, 0);// method_1 -> rem
  v7 = (void *)(v12 - 12);
  if ( (_UNKNOWN *)(v12 - 12) != &unk_2E140 )
  {
    v9 = (volatile signed __int32 *)(v12 - 4);
    if ( &pthread_create )
      v10 = _InterlockedExchangeAdd(v9, 0xFFFFFFFF);
    else
      v10 = (*v9)--;
    if ( v10 <= 0 )
      freeing(v7);
  }
  result = *MK_FP(__GS__, 20);
  if ( *MK_FP(__GS__, 20) == v45 )
    result = 1;
  return result;
}

int __cdecl patch(size_t page_size, int dexFileInMemory, char *method_name, char *method_class_path, int flag)
{
  int v5; // edi@1
  size_t v6; // eax@1
  int v7; // esi@1
  size_t v8; // eax@1
  int v9; // eax@1
  int v10; // ebp@1
  signed int v11; // edx@1
  int v12; // ecx@2
  int v13; // ebp@3
  _DWORD *v14; // ecx@3
  bool v15; // zf@5
  int v16; // esi@8
  _DWORD *v17; // ecx@9
  int v18; // ebp@9
  int v19; // ecx@14
  int v20; // esi@16
  int v21; // eax@17
  _DWORD *v22; // eax@17
  int v23; // eax@23
  int v24; // esi@23
  int result; // eax@23
  _WORD *v26; // eax@26

  v5 = dexFileInMemory;
  v6 = strlen(method_class_path);
  v7 = sub_5150(dexFileInMemory, method_class_path, v6);
  v8 = strlen(method_name);
  v9 = sub_5150(dexFileInMemory, method_name, v8);
  v10 = *(_DWORD *)(dexFileInMemory + 0x40);
  v11 = -1;
  if ( v10 )
  {
    v12 = *(_DWORD *)(dexFileInMemory + 0x44);
    v11 = 0;
    if ( *(_DWORD *)(v12 + dexFileInMemory) != v7 )
    {
      v13 = v10 - 1;
      v14 = (_DWORD *)(v12 + dexFileInMemory + 4);
      v11 = 0;
      while ( v13 != v11 )
      {
        ++v11;
        v15 = *v14 == v7;
        ++v14;
        if ( v15 )
          goto LABEL_8;
      }
      v11 = -1;
    }
  }
LABEL_8:
  v16 = *(_DWORD *)(dexFileInMemory + 88);
  if ( v16 )
  {
    v17 = (_DWORD *)(*(_DWORD *)(dexFileInMemory + 92) + dexFileInMemory + 4);
    v18 = 0;
    while ( *((_WORD *)v17 - 2) != v11 || *v17 != v9 )
    {
      ++v18;
      v17 += 2;
      if ( v16 == v18 )
      {
        v5 = dexFileInMemory;
        goto LABEL_14;
      }
    }
    v19 = v18;
    v5 = dexFileInMemory;
  }
  else
  {
LABEL_14:
    v19 = -1;
  }
  v20 = *(_DWORD *)(v5 + 96);
  if ( v20 )
  {
    v21 = *(_DWORD *)(v5 + 100);
    v15 = *(_DWORD *)(v21 + v5) == v11;
    v22 = (_DWORD *)(v21 + v5);
    if ( !v15 )
    {
      while ( --v20 )
      {
        v22 += 8;
        if ( *v22 == v11 )
          goto LABEL_23;
      }
      v22 = 0;
    }
  }
  else
  {
    v22 = 0;
  }
LABEL_23:
  v23 = sub_53C8(v5, (int)v22, v19);
  v24 = v23 + 16;
  result = mprotect((void *)(v23 - (v23 + 16) % page_size + 16), page_size, PROT_WRITE|PROT_READ);
  if ( flag != 2 )
  {
    if ( flag == 1 )
    {
      v26 = &add_opcodes;			// opcode patching
      goto LABEL_28;
    }
    if ( flag )
      return result;
  }
  v26 = &rem_opcodes;
LABEL_28:
  *(_WORD *)(v24 + 4) = v26[2];
  result = *(_DWORD *)v26;
  *(_DWORD *)v24 = result;
  return result;
}