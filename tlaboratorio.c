/*
FILE
	tlaboratorio.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tlaboratoriofunc.h
	while unxsRAD can still to be used to change this schema dependent file.
AUTHOR
	Template (C) 2001-2017 Gary Wallis for Unixservice, LLC.
TEMPLATE VARS AND FUNCTIONS
	funcModuleInput
	funcModuleCreateQuery
	funcModuleInsertQuery
	funcModuleListPrint
	funcModuleListTable
	funcModuleLoadVars
	funcModuleProcVars
	funcModuleUpdateQuery
	funcModuleVars
	funcModuleVarList
	cProject
	cTableKey
	cTableName
	cTableNameLC
	cTableTitle
*/


#include "mysqlrad.h"

//Table Variables
static unsigned uLaboratorio=0;
static char cLabel[33]={""};
static unsigned uPaciente=0;
static char cuPacientePullDown[256]={""};
static char cLaboratorio[65]={""};
static char *cOtro={""};
static unsigned uSangre=0;
static char cuSangrePullDown[256]={""};
static unsigned uSerologia=0;
static char cuSerologiaPullDown[256]={""};
static unsigned uOrina=0;
static char cuOrinaPullDown[256]={""};
static unsigned uMicrobiologia=0;
static char cuMicrobiologiaPullDown[256]={""};
static unsigned uVirologia=0;
static char cuVirologiaPullDown[256]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tLaboratorio "tLaboratorio.uLaboratorio,tLaboratorio.cLabel,tLaboratorio.uPaciente,tLaboratorio.cLaboratorio,tLaboratorio.cOtro,tLaboratorio.uSangre,tLaboratorio.uSerologia,tLaboratorio.uOrina,tLaboratorio.uMicrobiologia,tLaboratorio.uVirologia,tLaboratorio.uOwner,tLaboratorio.uCreatedBy,tLaboratorio.uCreatedDate,tLaboratorio.uModBy,tLaboratorio.uModDate"

 //Local only
void Insert_tLaboratorio(void);
void Update_tLaboratorio(char *cRowid);
void ProcesstLaboratorioListVars(pentry entries[], int x);

 //In tLaboratoriofunc.h file included below
void ExtProcesstLaboratorioVars(pentry entries[], int x);
void ExttLaboratorioCommands(pentry entries[], int x);
void ExttLaboratorioButtons(void);
void ExttLaboratorioNavBar(void);
void ExttLaboratorioGetHook(entry gentries[], int x);
void ExttLaboratorioSelect(void);
void ExttLaboratorioSelectRow(void);
void ExttLaboratorioListSelect(void);
void ExttLaboratorioListFilter(void);
void ExttLaboratorioAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tlaboratoriofunc.h"

 //Table Variables Assignment Function
void ProcesstLaboratorioVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uLaboratorio"))
			sscanf(entries[i].val,"%u",&uLaboratorio);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uPaciente"))
			sscanf(entries[i].val,"%u",&uPaciente);
		else if(!strcmp(entries[i].name,"cuPacientePullDown"))
		{
			sprintf(cuPacientePullDown,"%.255s",entries[i].val);
			uPaciente=ReadPullDown("tPaciente","cLabel",cuPacientePullDown);
		}
		else if(!strcmp(entries[i].name,"cLaboratorio"))
			sprintf(cLaboratorio,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cOtro"))
			cOtro=entries[i].val;
		else if(!strcmp(entries[i].name,"uSangre"))
			sscanf(entries[i].val,"%u",&uSangre);
		else if(!strcmp(entries[i].name,"cuSangrePullDown"))
		{
			sprintf(cuSangrePullDown,"%.255s",entries[i].val);
			uSangre=ReadPullDown("tSangre","cLabel",cuSangrePullDown);
		}
		else if(!strcmp(entries[i].name,"uSerologia"))
			sscanf(entries[i].val,"%u",&uSerologia);
		else if(!strcmp(entries[i].name,"cuSerologiaPullDown"))
		{
			sprintf(cuSerologiaPullDown,"%.255s",entries[i].val);
			uSerologia=ReadPullDown("tSerologia","cLabel",cuSerologiaPullDown);
		}
		else if(!strcmp(entries[i].name,"uOrina"))
			sscanf(entries[i].val,"%u",&uOrina);
		else if(!strcmp(entries[i].name,"cuOrinaPullDown"))
		{
			sprintf(cuOrinaPullDown,"%.255s",entries[i].val);
			uOrina=ReadPullDown("tOrina","cLabel",cuOrinaPullDown);
		}
		else if(!strcmp(entries[i].name,"uMicrobiologia"))
			sscanf(entries[i].val,"%u",&uMicrobiologia);
		else if(!strcmp(entries[i].name,"cuMicrobiologiaPullDown"))
		{
			sprintf(cuMicrobiologiaPullDown,"%.255s",entries[i].val);
			uMicrobiologia=ReadPullDown("tMicrobiologia","cLabel",cuMicrobiologiaPullDown);
		}
		else if(!strcmp(entries[i].name,"uVirologia"))
			sscanf(entries[i].val,"%u",&uVirologia);
		else if(!strcmp(entries[i].name,"cuVirologiaPullDown"))
		{
			sprintf(cuVirologiaPullDown,"%.255s",entries[i].val);
			uVirologia=ReadPullDown("tVirologia","cLabel",cuVirologiaPullDown);
		}
		else if(!strcmp(entries[i].name,"uOwner"))
			sscanf(entries[i].val,"%u",&uOwner);
		else if(!strcmp(entries[i].name,"uCreatedBy"))
			sscanf(entries[i].val,"%u",&uCreatedBy);
		else if(!strcmp(entries[i].name,"uCreatedDate"))
			sscanf(entries[i].val,"%lu",&uCreatedDate);
		else if(!strcmp(entries[i].name,"uModBy"))
			sscanf(entries[i].val,"%u",&uModBy);
		else if(!strcmp(entries[i].name,"uModDate"))
			sscanf(entries[i].val,"%lu",&uModDate);

	}

	//After so we can overwrite form data if needed.
	ExtProcesstLaboratorioVars(entries,x);

}//ProcesstLaboratorioVars()


void ProcesstLaboratorioListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstLaboratorioListVars(pentry entries[], int x)


int tLaboratorioCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttLaboratorioCommands(entries,x);

	if(!strcmp(gcFunction,"tLaboratorioTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tLaboratorioList();
		}

		//Default
		ProcesstLaboratorioVars(entries,x);
		tLaboratorio("");
	}
	else if(!strcmp(gcFunction,"tLaboratorioList"))
	{
		ProcessControlVars(entries,x);
		ProcesstLaboratorioListVars(entries,x);
		tLaboratorioList();
	}

	return(0);

}//tLaboratorioCommands()


void tLaboratorioInput(unsigned uMode)
{
	
	//uLaboratorio uRADType=1001
	OpenRow(LANG_FL_tLaboratorio_uLaboratorio,"black");
	printf("<input title='%s' type=text name=uLaboratorio value='%u' size=16 maxlength=10 "
		,LANG_FT_tLaboratorio_uLaboratorio,uLaboratorio);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uLaboratorio value='%u' >\n",uLaboratorio);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tLaboratorio_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tLaboratorio_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uPaciente COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uPaciente,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tPaciente;cuPacientePullDown","cLabel","cLabel",uPaciente,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tPaciente;cuPacientePullDown","cLabel","cLabel",uPaciente,0);
	else if(uMode)
		tTablePullDown("tPaciente;cuPacientePullDown","cLabel","cLabel",uPaciente,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tPaciente","cLabel",uPaciente));
		printf("<input type=hidden size=20 maxlength=20 name=uPaciente value='%u' >\n",uPaciente);
	}
	//cLaboratorio uRADType=253
	OpenRow(LANG_FL_tLaboratorio_cLaboratorio,"black");
	printf("<input title='%s' type=text name=cLaboratorio value='%s' size=64 maxlength=64 "
		,LANG_FT_tLaboratorio_cLaboratorio,EncodeDoubleQuotes(cLaboratorio));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLaboratorio value='%s'>\n",EncodeDoubleQuotes(cLaboratorio));
	}
	//cOtro COLTYPE_TEXT
	OpenRow(LANG_FL_tLaboratorio_cOtro,"black");
	printf("<textarea title='%s' cols=80 wrap=hard rows=16 name=cOtro "
,LANG_FT_tLaboratorio_cOtro);
	if(guPermLevel>=0 && uMode)
	{
		printf(">%s</textarea></td></tr>\n",cOtro);
	}
	else
	{
		printf("disabled>%s</textarea></td></tr>\n",cOtro);
		printf("<input type=hidden name=cOtro value=\"%s\" >\n",EncodeDoubleQuotes(cOtro));
	}
	//uSangre COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uSangre,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tSangre;cuSangrePullDown","cLabel","cLabel",uSangre,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tSangre;cuSangrePullDown","cLabel","cLabel",uSangre,0);
	else if(uMode)
		tTablePullDown("tSangre;cuSangrePullDown","cLabel","cLabel",uSangre,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tSangre","cLabel",uSangre));
		printf("<input type=hidden size=20 maxlength=20 name=uSangre value='%u' >\n",uSangre);
	}
	//uSerologia COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uSerologia,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tSerologia;cuSerologiaPullDown","cLabel","cLabel",uSerologia,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tSerologia;cuSerologiaPullDown","cLabel","cLabel",uSerologia,0);
	else if(uMode)
		tTablePullDown("tSerologia;cuSerologiaPullDown","cLabel","cLabel",uSerologia,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tSerologia","cLabel",uSerologia));
		printf("<input type=hidden size=20 maxlength=20 name=uSerologia value='%u' >\n",uSerologia);
	}
	//uOrina COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uOrina,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tOrina;cuOrinaPullDown","cLabel","cLabel",uOrina,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tOrina;cuOrinaPullDown","cLabel","cLabel",uOrina,0);
	else if(uMode)
		tTablePullDown("tOrina;cuOrinaPullDown","cLabel","cLabel",uOrina,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tOrina","cLabel",uOrina));
		printf("<input type=hidden size=20 maxlength=20 name=uOrina value='%u' >\n",uOrina);
	}
	//uMicrobiologia COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uMicrobiologia,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tMicrobiologia;cuMicrobiologiaPullDown","cLabel","cLabel",uMicrobiologia,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tMicrobiologia;cuMicrobiologiaPullDown","cLabel","cLabel",uMicrobiologia,0);
	else if(uMode)
		tTablePullDown("tMicrobiologia;cuMicrobiologiaPullDown","cLabel","cLabel",uMicrobiologia,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tMicrobiologia","cLabel",uMicrobiologia));
		printf("<input type=hidden size=20 maxlength=20 name=uMicrobiologia value='%u' >\n",uMicrobiologia);
	}
	//uVirologia COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tLaboratorio_uVirologia,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tVirologia;cuVirologiaPullDown","cLabel","cLabel",uVirologia,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tVirologia;cuVirologiaPullDown","cLabel","cLabel",uVirologia,0);
	else if(uMode)
		tTablePullDown("tVirologia;cuVirologiaPullDown","cLabel","cLabel",uVirologia,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tVirologia","cLabel",uVirologia));
		printf("<input type=hidden size=20 maxlength=20 name=uVirologia value='%u' >\n",uVirologia);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tLaboratorio_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tLaboratorio_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tLaboratorio_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tLaboratorio_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tLaboratorio_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tLaboratorioInput(unsigned uMode)


void tLaboratorio(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttLaboratorioSelectRow();
		else
			ExttLaboratorioSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetLaboratorio();
				unxsSalud("New tLaboratorio table created");
                	}
			else
			{
				htmlPlainTextError(mysql_error(&gMysql));
			}
        	}

		res=mysql_store_result(&gMysql);
		if((guI=mysql_num_rows(res)))
		{
			if(guMode==6)
			{
			sprintf(gcQuery,"SELECT _rowid FROM tLaboratorio WHERE uLaboratorio=%u"
						,uLaboratorio);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uLaboratorio);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uPaciente);
		sprintf(cLaboratorio,"%.64s",field[3]);
		cOtro=field[4];
		sscanf(field[5],"%u",&uSangre);
		sscanf(field[6],"%u",&uSerologia);
		sscanf(field[7],"%u",&uOrina);
		sscanf(field[8],"%u",&uMicrobiologia);
		sscanf(field[9],"%u",&uVirologia);
		sscanf(field[10],"%u",&uOwner);
		sscanf(field[11],"%u",&uCreatedBy);
		sscanf(field[12],"%lu",&uCreatedDate);
		sscanf(field[13],"%u",&uModBy);
		sscanf(field[14],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Laboratorio",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tLaboratorioTools>");
	printf("<input type=hidden name=gluRowid value=%lu>",gluRowid);
	if(guI)
	{
		if(guMode==6)
			//printf(" Found");
			printf(LANG_NBR_FOUND);
		else if(guMode==5)
			//printf(" Modified");
			printf(LANG_NBR_MODIFIED);
		else if(guMode==4)
			//printf(" New");
			printf(LANG_NBR_NEW);
		printf(LANG_NBRF_SHOWING,gluRowid,guI);
	}
	else
	{
		if(!cResult[0])
		//printf(" No records found");
		printf(LANG_NBR_NORECS);
	}
	if(cResult[0]) printf("%s",cResult);
	printf("</td></tr>");
	printf("<tr><td valign=top width=25%%>");

        ExttLaboratorioButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tLaboratorio Record Data",100);

	if(guMode==2000 || guMode==2002)
		tLaboratorioInput(1);
	else
		tLaboratorioInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttLaboratorioAuxTable();

	FooterRAD4();

}//end of tLaboratorio();


void NewtLaboratorio(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uLaboratorio FROM tLaboratorio WHERE uLaboratorio=%u",uLaboratorio);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tLaboratorio(LANG_NBR_RECEXISTS);

	Insert_tLaboratorio();
	uLaboratorio=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tLaboratorio",uLaboratorio);
	unxsSaludLog(uLaboratorio,"tLaboratorio","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uLaboratorio);
		tLaboratorio(gcQuery);
	}

}//NewtLaboratorio(unsigned uMode)


void DeletetLaboratorio(void)
{
	sprintf(gcQuery,"DELETE FROM tLaboratorio WHERE uLaboratorio=%u AND ( uOwner=%u OR %u>9 )"
					,uLaboratorio,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uLaboratorio,"tLaboratorio","Del");
		tLaboratorio(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uLaboratorio,"tLaboratorio","DelError");
		tLaboratorio(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetLaboratorio(void)


void Insert_tLaboratorio(void)
{
	sprintf(gcQuery,"INSERT INTO tLaboratorio SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"cLaboratorio='%s',"
		"cOtro='%s',"
		"uSangre=%u,"
		"uSerologia=%u,"
		"uOrina=%u,"
		"uMicrobiologia=%u,"
		"uVirologia=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uPaciente
			,TextAreaSave(cLaboratorio)
			,TextAreaSave(cOtro)
			,uSangre
			,uSerologia
			,uOrina
			,uMicrobiologia
			,uVirologia
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tLaboratorio(void)


void Update_tLaboratorio(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tLaboratorio SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"cLaboratorio='%s',"
		"cOtro='%s',"
		"uSangre=%u,"
		"uSerologia=%u,"
		"uOrina=%u,"
		"uMicrobiologia=%u,"
		"uVirologia=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uPaciente
			,TextAreaSave(cLaboratorio)
			,TextAreaSave(cOtro)
			,uSangre
			,uSerologia
			,uOrina
			,uMicrobiologia
			,uVirologia
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tLaboratorio(void)


void ModtLaboratorio(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tLaboratorio.uLaboratorio,"
				" tLaboratorio.uModDate"
				" FROM tLaboratorio,tClient"
				" WHERE tLaboratorio.uLaboratorio=%u"
				" AND tLaboratorio.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uLaboratorio,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uLaboratorio,uModDate FROM tLaboratorio"
				" WHERE uLaboratorio=%u"
					,uLaboratorio);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tLaboratorio(LANG_NBR_RECNOTEXIST);
	if(i>1) tLaboratorio(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tLaboratorio(LANG_NBR_EXTMOD);

	Update_tLaboratorio(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tLaboratorio",uLaboratorio);
	unxsSaludLog(uLaboratorio,"tLaboratorio","Mod");
	tLaboratorio(gcQuery);

}//ModtLaboratorio(void)


void tLaboratorioList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttLaboratorioListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tLaboratorioList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttLaboratorioListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uLaboratorio"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uPaciente"
		"<td><font face=arial,helvetica color=white>cLaboratorio"
		"<td><font face=arial,helvetica color=white>cOtro"
		"<td><font face=arial,helvetica color=white>uSangre"
		"<td><font face=arial,helvetica color=white>uSerologia"
		"<td><font face=arial,helvetica color=white>uOrina"
		"<td><font face=arial,helvetica color=white>uMicrobiologia"
		"<td><font face=arial,helvetica color=white>uVirologia"
		"<td><font face=arial,helvetica color=white>uOwner"
		"<td><font face=arial,helvetica color=white>uCreatedBy"
		"<td><font face=arial,helvetica color=white>uCreatedDate"
		"<td><font face=arial,helvetica color=white>uModBy"
		"<td><font face=arial,helvetica color=white>uModDate"
		"</tr>");



	mysql_data_seek(res,guStart-1);

	for(guN=0;guN<(guEnd-guStart+1);guN++)
	{
		field=mysql_fetch_row(res);
		if(!field)
		{
			printf("<tr><td><font face=arial,helvetica>End of data</table>");
			FooterRAD4();
		}
			if(guN % 2)
				printf("<tr bgcolor=#BBE1D3>");
			else
				printf("<tr>");
				char cBuf2[128];
		sprintf(cBuf2,"<a class=darkLink href=?gcFunction=tPaciente&uPaciente=%.32s>%.32s</a>",
			field[2],
			ForeignKey("tPaciente","cLabel",strtoul(field[2],NULL,10)));
		char cBuf5[128];
		sprintf(cBuf5,"<a class=darkLink href=?gcFunction=tSangre&uSangre=%.32s>%.32s</a>",
			field[5],
			ForeignKey("tSangre","cLabel",strtoul(field[5],NULL,10)));
		char cBuf6[128];
		sprintf(cBuf6,"<a class=darkLink href=?gcFunction=tSerologia&uSerologia=%.32s>%.32s</a>",
			field[6],
			ForeignKey("tSerologia","cLabel",strtoul(field[6],NULL,10)));
		char cBuf7[128];
		sprintf(cBuf7,"<a class=darkLink href=?gcFunction=tOrina&uOrina=%.32s>%.32s</a>",
			field[7],
			ForeignKey("tOrina","cLabel",strtoul(field[7],NULL,10)));
		char cBuf8[128];
		sprintf(cBuf8,"<a class=darkLink href=?gcFunction=tMicrobiologia&uMicrobiologia=%.32s>%.32s</a>",
			field[8],
			ForeignKey("tMicrobiologia","cLabel",strtoul(field[8],NULL,10)));
		char cBuf9[128];
		sprintf(cBuf9,"<a class=darkLink href=?gcFunction=tVirologia&uVirologia=%.32s>%.32s</a>",
			field[9],
			ForeignKey("tVirologia","cLabel",strtoul(field[9],NULL,10)));
		char cBuf10[128];
		sprintf(cBuf10,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[10],
			ForeignKey("tClient","cLabel",strtoul(field[10],NULL,10)));
		char cBuf11[128];
		sprintf(cBuf11,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[11],
			ForeignKey("tClient","cLabel",strtoul(field[11],NULL,10)));
		time_t luTime12=strtoul(field[12],NULL,10);
		char cBuf12[32];
		if(luTime12)
			ctime_r(&luTime12,cBuf12);
		else
			sprintf(cBuf12,"---");
		char cBuf13[128];
		sprintf(cBuf13,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[13],
			ForeignKey("tClient","cLabel",strtoul(field[13],NULL,10)));
		time_t luTime14=strtoul(field[14],NULL,10);
		char cBuf14[32];
		if(luTime14)
			ctime_r(&luTime14,cBuf14);
		else
			sprintf(cBuf14,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tLaboratorio&uLaboratorio=%s>%s</a><td>%s<td>%s<td>%s<td><textarea disabled>%s</textarea><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,cBuf2
			,field[3]
			,field[4]
			,cBuf5
			,cBuf6
			,cBuf7
			,cBuf8
			,cBuf9
			,cBuf10
			,cBuf11
			,cBuf12
			,cBuf13
			,cBuf14
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tLaboratorioList()


void CreatetLaboratorio(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tLaboratorio ("
		"uLaboratorio INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uPaciente INT UNSIGNED ,"
		"cLaboratorio VARCHAR(64) NOT NULL DEFAULT '',"
		"cOtro TEXT NOT NULL DEFAULT '',"
		"uSangre INT UNSIGNED ,"
		"uSerologia INT UNSIGNED ,"
		"uOrina INT UNSIGNED ,"
		"uMicrobiologia INT UNSIGNED ,"
		"uVirologia INT UNSIGNED ,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetLaboratorio(void)



