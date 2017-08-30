#
#FILE
#       unxsSalud/Makefile
#       From unxsRAD/templates/default/RAD4/Makefile template.
#AUTHOR/LEGAL
#       Template (C) 2001-2017 Gary Wallis for Unixservice. GPLv2 license applies.
#NOTES
#	Only tested on modern CentOS and Ubuntu
#

#CFLAGS=-O -DLinux -Wall -pedantic
GIT_VERSION := $(shell git describe --dirty --always --tags 2> /dev/null || echo "noGit")
CFLAGS= -DLinux -Wall -DdsGitVersion=\"$(GIT_VERSION)\"
RELEASE= 0.1
#If using lib64 make sure you have adjusted if any errors emerge
LIBS= -L/usr/lib/openisp -L/usr/lib64/mysql -lmysqlclient -lz -lcrypt -lm -lssl -ltemplate
CGIDIR=/var/www/cgi-bin/

all: unxsSalud.cgi unxsSalud

#New standalone CLI job queue model
unxsSalud: unxssalud.o mysqlconnect.o
	cc unxssalud.o mysqlconnect.o -o unxsSalud $(LIBS)

unxssalud.o: unxssalud.c mysqlrad.h local.h mysqlconnect.c
	cc -c unxssalud.c -o unxssalud.o $(CFLAGS)

#unxsRAD comes with a sample standalone program rename
unxssalud.c: unxsrad.c
	@ if [ ! -f unxssalud.c ];then cp -i unxsrad.c unxssalud.c; fi

#included standard RAD4 objects
unxsSalud.cgi: tpaciente.o tconsulta.o tmotivo.o tcentro.o tantecedente.o tinternacion.o tmedico.o tmedicacion.o tinmunizacion.o ttipoconsulta.o tlaboratorio.o tsangre.o tserologia.o tmicrobiologia.o themocultivo.o turocultivo.o tcultivocateter.o tcultivopb.o tcultivohueso.o tcultivoesputo.o tcultivolcr.o torina.o tvirologia.o tvitales.o tclient.o tauthorize.o tserver.o tconfiguration.o tstatus.o tjobstatus.o tjob.o tglossary.o ttemplate.o ttemplateset.o ttemplatetype.o tlog.o tlogtype.o tlogmonth.o tmonth.o  mysqlconnect.o main.o cgi.o
	cc tpaciente.o tconsulta.o tmotivo.o tcentro.o tantecedente.o tinternacion.o tmedico.o tmedicacion.o tinmunizacion.o ttipoconsulta.o tlaboratorio.o tsangre.o tserologia.o tmicrobiologia.o themocultivo.o turocultivo.o tcultivocateter.o tcultivopb.o tcultivohueso.o tcultivoesputo.o tcultivolcr.o torina.o tvirologia.o tvitales.o tclient.o tauthorize.o tserver.o tconfiguration.o tstatus.o tjobstatus.o tjob.o tglossary.o ttemplate.o ttemplateset.o ttemplatetype.o tlog.o tlogtype.o tlogmonth.o tmonth.o  mysqlconnect.o main.o cgi.o -o unxsSalud.cgi $(LIBS) 

tpaciente.o: tpaciente.c mysqlrad.h language.h tpacientefunc.h local.h
	cc -c tpaciente.c -o tpaciente.o $(CFLAGS)

tconsulta.o: tconsulta.c mysqlrad.h language.h tconsultafunc.h local.h
	cc -c tconsulta.c -o tconsulta.o $(CFLAGS)

tmotivo.o: tmotivo.c mysqlrad.h language.h tmotivofunc.h local.h
	cc -c tmotivo.c -o tmotivo.o $(CFLAGS)

tcentro.o: tcentro.c mysqlrad.h language.h tcentrofunc.h local.h
	cc -c tcentro.c -o tcentro.o $(CFLAGS)

tantecedente.o: tantecedente.c mysqlrad.h language.h tantecedentefunc.h local.h
	cc -c tantecedente.c -o tantecedente.o $(CFLAGS)

tinternacion.o: tinternacion.c mysqlrad.h language.h tinternacionfunc.h local.h
	cc -c tinternacion.c -o tinternacion.o $(CFLAGS)

tmedico.o: tmedico.c mysqlrad.h language.h tmedicofunc.h local.h
	cc -c tmedico.c -o tmedico.o $(CFLAGS)

tmedicacion.o: tmedicacion.c mysqlrad.h language.h tmedicacionfunc.h local.h
	cc -c tmedicacion.c -o tmedicacion.o $(CFLAGS)

tinmunizacion.o: tinmunizacion.c mysqlrad.h language.h tinmunizacionfunc.h local.h
	cc -c tinmunizacion.c -o tinmunizacion.o $(CFLAGS)

ttipoconsulta.o: ttipoconsulta.c mysqlrad.h language.h ttipoconsultafunc.h local.h
	cc -c ttipoconsulta.c -o ttipoconsulta.o $(CFLAGS)

tlaboratorio.o: tlaboratorio.c mysqlrad.h language.h tlaboratoriofunc.h local.h
	cc -c tlaboratorio.c -o tlaboratorio.o $(CFLAGS)

tsangre.o: tsangre.c mysqlrad.h language.h tsangrefunc.h local.h
	cc -c tsangre.c -o tsangre.o $(CFLAGS)

tserologia.o: tserologia.c mysqlrad.h language.h tserologiafunc.h local.h
	cc -c tserologia.c -o tserologia.o $(CFLAGS)

tmicrobiologia.o: tmicrobiologia.c mysqlrad.h language.h tmicrobiologiafunc.h local.h
	cc -c tmicrobiologia.c -o tmicrobiologia.o $(CFLAGS)

themocultivo.o: themocultivo.c mysqlrad.h language.h themocultivofunc.h local.h
	cc -c themocultivo.c -o themocultivo.o $(CFLAGS)

turocultivo.o: turocultivo.c mysqlrad.h language.h turocultivofunc.h local.h
	cc -c turocultivo.c -o turocultivo.o $(CFLAGS)

tcultivocateter.o: tcultivocateter.c mysqlrad.h language.h tcultivocateterfunc.h local.h
	cc -c tcultivocateter.c -o tcultivocateter.o $(CFLAGS)

tcultivopb.o: tcultivopb.c mysqlrad.h language.h tcultivopbfunc.h local.h
	cc -c tcultivopb.c -o tcultivopb.o $(CFLAGS)

tcultivohueso.o: tcultivohueso.c mysqlrad.h language.h tcultivohuesofunc.h local.h
	cc -c tcultivohueso.c -o tcultivohueso.o $(CFLAGS)

tcultivoesputo.o: tcultivoesputo.c mysqlrad.h language.h tcultivoesputofunc.h local.h
	cc -c tcultivoesputo.c -o tcultivoesputo.o $(CFLAGS)

tcultivolcr.o: tcultivolcr.c mysqlrad.h language.h tcultivolcrfunc.h local.h
	cc -c tcultivolcr.c -o tcultivolcr.o $(CFLAGS)

torina.o: torina.c mysqlrad.h language.h torinafunc.h local.h
	cc -c torina.c -o torina.o $(CFLAGS)

tvirologia.o: tvirologia.c mysqlrad.h language.h tvirologiafunc.h local.h
	cc -c tvirologia.c -o tvirologia.o $(CFLAGS)

tvitales.o: tvitales.c mysqlrad.h language.h tvitalesfunc.h local.h
	cc -c tvitales.c -o tvitales.o $(CFLAGS)

tclient.o: tclient.c mysqlrad.h language.h tclientfunc.h local.h
	cc -c tclient.c -o tclient.o $(CFLAGS)

tauthorize.o: tauthorize.c mysqlrad.h language.h tauthorizefunc.h local.h
	cc -c tauthorize.c -o tauthorize.o $(CFLAGS)

tserver.o: tserver.c mysqlrad.h language.h tserverfunc.h local.h
	cc -c tserver.c -o tserver.o $(CFLAGS)

tconfiguration.o: tconfiguration.c mysqlrad.h language.h tconfigurationfunc.h local.h
	cc -c tconfiguration.c -o tconfiguration.o $(CFLAGS)

tstatus.o: tstatus.c mysqlrad.h language.h tstatusfunc.h local.h
	cc -c tstatus.c -o tstatus.o $(CFLAGS)

tjobstatus.o: tjobstatus.c mysqlrad.h language.h tjobstatusfunc.h local.h
	cc -c tjobstatus.c -o tjobstatus.o $(CFLAGS)

tjob.o: tjob.c mysqlrad.h language.h tjobfunc.h local.h
	cc -c tjob.c -o tjob.o $(CFLAGS)

tglossary.o: tglossary.c mysqlrad.h language.h tglossaryfunc.h local.h
	cc -c tglossary.c -o tglossary.o $(CFLAGS)

ttemplate.o: ttemplate.c mysqlrad.h language.h ttemplatefunc.h local.h
	cc -c ttemplate.c -o ttemplate.o $(CFLAGS)

ttemplateset.o: ttemplateset.c mysqlrad.h language.h ttemplatesetfunc.h local.h
	cc -c ttemplateset.c -o ttemplateset.o $(CFLAGS)

ttemplatetype.o: ttemplatetype.c mysqlrad.h language.h ttemplatetypefunc.h local.h
	cc -c ttemplatetype.c -o ttemplatetype.o $(CFLAGS)

tlog.o: tlog.c mysqlrad.h language.h tlogfunc.h local.h
	cc -c tlog.c -o tlog.o $(CFLAGS)

tlogtype.o: tlogtype.c mysqlrad.h language.h tlogtypefunc.h local.h
	cc -c tlogtype.c -o tlogtype.o $(CFLAGS)

tlogmonth.o: tlogmonth.c mysqlrad.h language.h tlogmonthfunc.h local.h
	cc -c tlogmonth.c -o tlogmonth.o $(CFLAGS)

tmonth.o: tmonth.c mysqlrad.h language.h tmonthfunc.h local.h
	cc -c tmonth.c -o tmonth.o $(CFLAGS)



#standard RAD4 
main.o: main.c mysqlrad.h mainfunc.h language.h local.h
	cc -c main.c -o main.o $(CFLAGS)

cgi.o: cgi.h cgi.c
	cc -c cgi.c -o cgi.o $(CFLAGS)

mysqlconnect.o: mysqlconnect.c mysqlrad.h local.h
	cc -c mysqlconnect.c -o mysqlconnect.o $(CFLAGS)

local.h: local.h.default
	@ if [ ! -f local.h ];then cp -i local.h.default local.h; fi

clean:
	rm -f *.o

cleandist:
	rm -f *.o *.gz

install: unxsSalud.cgi unxsSalud
	install -s unxsSalud.cgi $(CGIDIR)unxsSalud.cgi
	install -s unxsSalud /usr/sbin/unxsSalud
	rm unxsSalud.cgi
	rm unxsSalud
