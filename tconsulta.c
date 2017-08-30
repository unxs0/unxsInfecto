/*
FILE
	tconsulta.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tconsultafunc.h
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
static unsigned uConsulta=0;
static char cLabel[33]={""};
static unsigned uPaciente=0;
static char cuPacientePullDown[256]={""};
static unsigned uVitales=0;
static char cuVitalesPullDown[256]={""};
static unsigned uLaboratorio=0;
static char cuLaboratorioPullDown[256]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tConsulta "tConsulta.uConsulta,tConsulta.cLabel,tConsulta.uPaciente,tConsulta.uVitales,tConsulta.uLaboratorio,tConsulta.uOwner,tConsulta.uCreatedBy,tConsulta.uCreatedDate,tConsulta.uModBy,tConsulta.uModDate"

 //Local only
void Insert_tConsulta(void);
void Update_tConsulta(char *cRowid);
void ProcesstConsultaListVars(pentry entries[], int x);

 //In tConsultafunc.h file included below
void ExtProcesstConsultaVars(pentry entries[], int x);
void ExttConsultaCommands(pentry entries[], int x);
void ExttConsultaButtons(void);
void ExttConsultaNavBar(void);
void ExttConsultaGetHook(entry gentries[], int x);
void ExttConsultaSelect(void);
void ExttConsultaSelectRow(void);
void ExttConsultaListSelect(void);
void ExttConsultaListFilter(void);
void ExttConsultaAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tconsultafunc.h"

 //Table Variables Assignment Function
void ProcesstConsultaVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uConsulta"))
			sscanf(entries[i].val,"%u",&uConsulta);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uPaciente"))
			sscanf(entries[i].val,"%u",&uPaciente);
		else if(!strcmp(entries[i].name,"cuPacientePullDown"))
		{
			sprintf(cuPacientePullDown,"%.255s",entries[i].val);
			uPaciente=ReadPullDown("tPaciente","cLabel",cuPacientePullDown);
		}
		else if(!strcmp(entries[i].name,"uVitales"))
			sscanf(entries[i].val,"%u",&uVitales);
		else if(!strcmp(entries[i].name,"cuVitalesPullDown"))
		{
			sprintf(cuVitalesPullDown,"%.255s",entries[i].val);
			uVitales=ReadPullDown("tVitales","cLabel",cuVitalesPullDown);
		}
		else if(!strcmp(entries[i].name,"uLaboratorio"))
			sscanf(entries[i].val,"%u",&uLaboratorio);
		else if(!strcmp(entries[i].name,"cuLaboratorioPullDown"))
		{
			sprintf(cuLaboratorioPullDown,"%.255s",entries[i].val);
			uLaboratorio=ReadPullDown("tLaboratorio","cLabel",cuLaboratorioPullDown);
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
	ExtProcesstConsultaVars(entries,x);

}//ProcesstConsultaVars()


void ProcesstConsultaListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstConsultaListVars(pentry entries[], int x)


int tConsultaCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttConsultaCommands(entries,x);

	if(!strcmp(gcFunction,"tConsultaTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tConsultaList();
		}

		//Default
		ProcesstConsultaVars(entries,x);
		tConsulta("");
	}
	else if(!strcmp(gcFunction,"tConsultaList"))
	{
		ProcessControlVars(entries,x);
		ProcesstConsultaListVars(entries,x);
		tConsultaList();
	}

	return(0);

}//tConsultaCommands()


void tConsultaInput(unsigned uMode)
{
	
	//uConsulta uRADType=1001
	OpenRow(LANG_FL_tConsulta_uConsulta,"black");
	printf("<input title='%s' type=text name=uConsulta value='%u' size=16 maxlength=10 "
		,LANG_FT_tConsulta_uConsulta,uConsulta);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uConsulta value='%u' >\n",uConsulta);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tConsulta_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tConsulta_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tConsulta_uPaciente,"black");
	if(guPermLevel>=7 && guPermLevel<10 && uMode)
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
	//uVitales COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tConsulta_uVitales,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tVitales;cuVitalesPullDown","cLabel","cLabel",uVitales,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tVitales;cuVitalesPullDown","cLabel","cLabel",uVitales,0);
	else if(uMode)
		tTablePullDown("tVitales;cuVitalesPullDown","cLabel","cLabel",uVitales,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tVitales","cLabel",uVitales));
		printf("<input type=hidden size=20 maxlength=20 name=uVitales value='%u' >\n",uVitales);
	}
	//uLaboratorio COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tConsulta_uLaboratorio,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tLaboratorio;cuLaboratorioPullDown","cLabel","cLabel",uLaboratorio,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tLaboratorio;cuLaboratorioPullDown","cLabel","cLabel",uLaboratorio,0);
	else if(uMode)
		tTablePullDown("tLaboratorio;cuLaboratorioPullDown","cLabel","cLabel",uLaboratorio,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tLaboratorio","cLabel",uLaboratorio));
		printf("<input type=hidden size=20 maxlength=20 name=uLaboratorio value='%u' >\n",uLaboratorio);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tConsulta_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tConsulta_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tConsulta_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tConsulta_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tConsulta_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tConsultaInput(unsigned uMode)


void tConsulta(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttConsultaSelectRow();
		else
			ExttConsultaSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetConsulta();
				unxsSalud("New tConsulta table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tConsulta WHERE uConsulta=%u"
						,uConsulta);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uConsulta);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uPaciente);
		sscanf(field[3],"%u",&uVitales);
		sscanf(field[4],"%u",&uLaboratorio);
		sscanf(field[5],"%u",&uOwner);
		sscanf(field[6],"%u",&uCreatedBy);
		sscanf(field[7],"%lu",&uCreatedDate);
		sscanf(field[8],"%u",&uModBy);
		sscanf(field[9],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de consultas",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tConsultaTools>");
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

        ExttConsultaButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tConsulta Record Data",100);

	if(guMode==2000 || guMode==2002)
		tConsultaInput(1);
	else
		tConsultaInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttConsultaAuxTable();

	FooterRAD4();

}//end of tConsulta();


void NewtConsulta(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uConsulta FROM tConsulta WHERE uConsulta=%u",uConsulta);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tConsulta(LANG_NBR_RECEXISTS);

	Insert_tConsulta();
	uConsulta=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tConsulta",uConsulta);
	unxsSaludLog(uConsulta,"tConsulta","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uConsulta);
		tConsulta(gcQuery);
	}

}//NewtConsulta(unsigned uMode)


void DeletetConsulta(void)
{
	sprintf(gcQuery,"DELETE FROM tConsulta WHERE uConsulta=%u AND ( uOwner=%u OR %u>9 )"
					,uConsulta,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uConsulta,"tConsulta","Del");
		tConsulta(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uConsulta,"tConsulta","DelError");
		tConsulta(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetConsulta(void)


void Insert_tConsulta(void)
{
	sprintf(gcQuery,"INSERT INTO tConsulta SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"uVitales=%u,"
		"uLaboratorio=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uPaciente
			,uVitales
			,uLaboratorio
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tConsulta(void)


void Update_tConsulta(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tConsulta SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"uVitales=%u,"
		"uLaboratorio=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uPaciente
			,uVitales
			,uLaboratorio
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tConsulta(void)


void ModtConsulta(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tConsulta.uConsulta,"
				" tConsulta.uModDate"
				" FROM tConsulta,tClient"
				" WHERE tConsulta.uConsulta=%u"
				" AND tConsulta.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uConsulta,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uConsulta,uModDate FROM tConsulta"
				" WHERE uConsulta=%u"
					,uConsulta);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tConsulta(LANG_NBR_RECNOTEXIST);
	if(i>1) tConsulta(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tConsulta(LANG_NBR_EXTMOD);

	Update_tConsulta(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tConsulta",uConsulta);
	unxsSaludLog(uConsulta,"tConsulta","Mod");
	tConsulta(gcQuery);

}//ModtConsulta(void)


void tConsultaList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttConsultaListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tConsultaList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttConsultaListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uConsulta"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uPaciente"
		"<td><font face=arial,helvetica color=white>uVitales"
		"<td><font face=arial,helvetica color=white>uLaboratorio"
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
		char cBuf3[128];
		sprintf(cBuf3,"<a class=darkLink href=?gcFunction=tVitales&uVitales=%.32s>%.32s</a>",
			field[3],
			ForeignKey("tVitales","cLabel",strtoul(field[3],NULL,10)));
		char cBuf4[128];
		sprintf(cBuf4,"<a class=darkLink href=?gcFunction=tLaboratorio&uLaboratorio=%.32s>%.32s</a>",
			field[4],
			ForeignKey("tLaboratorio","cLabel",strtoul(field[4],NULL,10)));
		char cBuf5[128];
		sprintf(cBuf5,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[5],
			ForeignKey("tClient","cLabel",strtoul(field[5],NULL,10)));
		char cBuf6[128];
		sprintf(cBuf6,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[6],
			ForeignKey("tClient","cLabel",strtoul(field[6],NULL,10)));
		time_t luTime7=strtoul(field[7],NULL,10);
		char cBuf7[32];
		if(luTime7)
			ctime_r(&luTime7,cBuf7);
		else
			sprintf(cBuf7,"---");
		char cBuf8[128];
		sprintf(cBuf8,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[8],
			ForeignKey("tClient","cLabel",strtoul(field[8],NULL,10)));
		time_t luTime9=strtoul(field[9],NULL,10);
		char cBuf9[32];
		if(luTime9)
			ctime_r(&luTime9,cBuf9);
		else
			sprintf(cBuf9,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tConsulta&uConsulta=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,cBuf2
			,cBuf3
			,cBuf4
			,cBuf5
			,cBuf6
			,cBuf7
			,cBuf8
			,cBuf9
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tConsultaList()


void CreatetConsulta(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tConsulta ("
		"uConsulta INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uPaciente INT UNSIGNED ,"
		"uVitales INT UNSIGNED ,"
		"uLaboratorio INT UNSIGNED ,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetConsulta(void)



