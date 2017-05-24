package com.rctf.hellodalvik;

import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.TextView;
import com.rctf.hellodalvik.MainActivity;

class MainActivity$1 implements OnClickListener {
   // $FF: synthetic field
   final MainActivity this$0;
   // $FF: synthetic field
   final EditText val$editText;
   // $FF: synthetic field
   final String[] val$kk;
   // $FF: synthetic field
   final TextView val$tv;

   MainActivity$1(MainActivity var1, EditText var2, String[] var3, TextView var4) {
      this.this$0 = var1;
      this.val$editText = var2;
      this.val$kk = var3;
      this.val$tv = var4;
   }

   public void onClick(View var1) {
      String var5 = String.valueOf(this.val$editText.getText());
      String var8 = "";
      boolean var3 = false;
      char[] var6 = var5.toCharArray();

      for(int var2 = 0; var2 < var6.length; var8 = var5) {
         boolean var4 = var3;
         var5 = var8;
         if(var2 % 3 == 0) {
            var5 = "";

            for(int var9 = 0; var9 < 3; ++var9) {
               var5 = var5 + var6[(var2 + var9) % var6.length];
            }

            char[] var7 = MainActivity.process_1(this.this$0, var5);
            this.val$kk[0] = MainActivity.process_2(this.this$0, var7, var5);
            if(this.val$kk[0].equals(MainActivity.hashArray(this.this$0)[var2 / 3 % 4])) {
               var5 = var8 + var5;
               var4 = var3;
            } else {
               this.val$tv.setText("Too Young!!");
               var4 = true;
               var5 = var8;
            }
         }

         ++var2;
         var3 = var4;
      }

      if(!var3) {
         this.val$tv.setText("RCTF{" + var8 + "}");
      }

   }
}
