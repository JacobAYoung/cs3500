import sys, os


os.chdir('../hw5/input')
for file_in_input in os.listdir():
        if file_in_input == "bigLet.txt":
                #print('------------- %s ---------------------'%(file_in_input))
                os.system('../a.out %s > ../result/%s.out' % (file_in_input, file_in_input));
                os.system('diff -c ../result/%s.out ../output/%s.out --ignore-space-change --ignore-case --ignore-blank-lines' % (file_in_input,file_in_input))

				#bigLet
				#letPrint
				#letPrintIf
				#nestedLet
				#printExprList
				#relop_int_int1
				#relop_int_int2
				#relop_str_str2