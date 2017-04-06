filePDF = join.pdf
fileEPS  = join.eps
filePS  = join.ps

ps:	$(filePS)
eps:	$(fileEPS)
pdf:	$(filePDF)

join.eps: join.ps
	rm -f join.eps
	ps2eps join.ps

join.ps: join.ms
	pic join.ms | groff -ms > join.ps

join.pdf: join.eps
	epspdf join.eps

clear:
	rm -f *.ps *.pdf
