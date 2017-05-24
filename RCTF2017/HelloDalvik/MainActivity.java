package com.rctf.hellodalvik;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import com.rctf.hellodalvik.MathMethod;
import com.rctf.hellodalvik.MainActivity.1;

public class MainActivity extends AppCompatActivity {
   private String[] angry = new String[]{"6F50D5057EFB2B9411C1B237E7D8588D", "98DD67FE3789D499AB3AF3CD1055EB76", "10556D767F835C91A9B2BBCF98DDE4FE", "72AD4A98C3603EE1865407ACFA25C210"};
   private String code = "a#s224kfuSaom=D469asSkOdhmP34!@-";
   private int int_1;
   private int int_2;
   private int int_3;
   private int int_4;
   private String hexdigits = "0123456789ABCDEF";
   private int int_5;
   private int int_6;
   private char[] codeCharArr;
   private int int_7 = 255;
   private int int_8;

   public MainActivity() {
      System.loadLibrary("native-lib");
      Log.d("Have Fine! ", this.stringFromJNI() + "");
   }

   // $FF: synthetic method
   static char[] process_1(MainActivity var0, String var1) {
      return var0.processString1(var1);
   }

   // $FF: synthetic method
   static String process_2(MainActivity var0, char[] var1, String var2) {
      return var0.processString2(var1, var2);
   }

   // $FF: synthetic method
   static String[] angryHashArray(MainActivity var0) {
      return var0.angry;
   }

   private String processString2(char[] var1, String var2) {
      String var4 = "";
      if(var1.length != 32) {
         return null;
      } else {
         char[] var5 = var2.toCharArray();
         char[] var6 = this.hexdigits.toCharArray();

         int var3;
         for(var3 = 0; var3 < var5.length; ++var3) {
            var5[var3] = (char)(var5[var3] / 10 % 10);
         }

         var3 = 0;

         for(var2 = var4; var3 < 32; ++var3) {
            var2 = var2 + var6[(var5[var3 % var5.length] + var1[var3]) % 16];
         }

         return var2;
      }
   }

   private void codeToCharArr() {
      this.codeCharArr = this.code.toCharArray();
   }

   private char[] processString1(String var1) {
      char[] var3 = new char[32];
      char[] var4 = var1.toCharArray();

      int var2;
      for(var2 = 0; var2 < var4.length; ++var2) {
         var4[var2] = (char)(var4[var2] % 10);
      }

      for(var2 = 0; var2 < 32; ++var2) {
         this.int_8 = (new MathMethod()).rem(var2, var4.length);	//MathMethod_3
         this.int_2 = (new MathMethod()).rem(var2, this.codeCharArr.length);	//MathMethod_3
         this.int_3 = (new MathMethod()).div(this.int_2, var4[this.int_8]);		//MathMethod_4
         this.int_4 = (new MathMethod()).plus(this.int_3, this.codeCharArr[this.int_2]);	//MathMethod_1
         this.int_6 = (new MathMethod()).mul(this.int_3, this.int_4);	//MathMethod_2
         this.int_5 = (new MathMethod()).xor(this.int_4, this.codeCharArr[this.int_8]);	//MathMethod_5
         this.int_1 = (new MathMethod()).div(this.int_6, this.int_5);	//MathMethod_4
         var3[var2] = (char)(this.int_1 & this.int_7);
      }

      return var3;
   }

   protected void onCreate(Bundle var1) {
      String[] var2 = new String[1];
      super.onCreate(var1);
      this.setContentView(2130968603);
      this.codeToCharArr();
      TextView var4 = (TextView)this.findViewById(2131427424);
      EditText var3 = (EditText)this.findViewById(2131427422);
      ((Button)this.findViewById(2131427423)).setOnClickListener(new 1(this, var3, var2, var4));
   }

   public native int stringFromJNI();
}
