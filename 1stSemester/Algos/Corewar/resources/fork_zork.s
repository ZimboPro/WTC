.name "zork"
.comment "I'M ALIIIIVE"

fork	%:l3
fork	%:l4
fork	%:l2
l2:		sti r1 %:live1  %1
		and r1 %0 r1

live1:	live %1
		zjmp %:live1

l3:		sti r1 %:live2  %1
		and r1 %0 r1

live2:	live %1
		zjmp %:live2

l4:		sti r1 %:live3  %1
		and r1 %0 r1

live3:	live %1
		zjmp %:live3
