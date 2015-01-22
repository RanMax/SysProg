 #!/bin/bash
 
 for file in ${PATH//:/ }; do
-    find $file -type f -perm 0005  
+    find $file -type f -perm /o+rx
 done
 
