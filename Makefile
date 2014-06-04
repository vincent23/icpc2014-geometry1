OUTDIR := out
SOURCES := $(shell ls *.tex)
OUT := geometry.pdf

main: ${OUT}

%.pdf: %.tex
	latexmk -pdf --output-directory=${OUTDIR} -auxdir=${OUTDIR} $<

clean:
	$(RM) -r ${OUTDIR}/*
