/*
FILE
	tcultivopb.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tcultivopbfunc.h
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
static unsigned uCultivoPB=0;
static char cLabel[33]={""};
static char cBacteria[66]={""};
static char *cSensibilidad={""};
static char *cResistencia={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tCultivoPB "tCultivoPB.uCultivoPB,tCultivoPB.cLabel,tCultivoPB.cBacteria,tCultivoPB.cSensibilidad,tCultivoPB.cResistencia,tCultivoPB.uOwner,tCultivoPB.uCreatedBy,tCultivoPB.uCreatedDate,tCultivoPB.uModBy,tCultivoPB.uModDate"

 //Local only
void Insert_tCultivoPB(void);
void Update_tCultivoPB(char *cRowid);
void ProcesstCultivoPBListVars(pentry entries[], int x);

 //In tCultivoPBfunc.h file included below
void ExtProcesstCultivoPBVars(pentry entries[], int x);
void ExttCultivoPBCommands(pentry entries[], int x);
void ExttCultivoPBButtons(void);
void ExttCultivoPBNavBar(void);
void ExttCultivoPBGetHook(entry gentries[], int x);
void ExttCultivoPBSelect(void);
void ExttCultivoPBSelectRow(void);
void ExttCultivoPBListSelect(void);
void ExttCultivoPBListFilter(void);
void ExttCultivoPBAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tcultivopbfunc.h"

 //Table Variables Assignment Function
void ProcesstCultivoPBVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uCultivoPB"))
			sscanf(entries[i].val,"%u",&uCultivoPB);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"cBacteria"))
			sprintf(cBacteria,"%.65s",entries[i].val);
		else if(!strcmp(entries[i].name,"cSensibilidad"))
			cSensibilidad=entries[i].val;
		else if(!strcmp(entries[i].name,"cResistencia"))
			cResistencia=entries[i].val;
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
	ExtProcesstCultivoPBVars(entries,x);

}//ProcesstCultivoPBVars()


void ProcesstCultivoPBListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstCultivoPBListVars(pentry entries[], int x)


int tCultivoPBCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttCultivoPBCommands(entries,x);

	if(!strcmp(gcFunction,"tCultivoPBTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tCultivoPBList();
		}

		//Default
		ProcesstCultivoPBVars(entries,x);
		tCultivoPB("");
	}
	else if(!strcmp(gcFunction,"tCultivoPBList"))
	{
		ProcessControlVars(entries,x);
		ProcesstCultivoPBListVars(entries,x);
		tCultivoPBList();
	}

	return(0);

}//tCultivoPBCommands()


void tCultivoPBInput(unsigned uMode)
{
	
	//uCultivoPB uRADType=1001
	OpenRow(LANG_FL_tCultivoPB_uCultivoPB,"black");
	printf("<input title='%s' type=text name=uCultivoPB value='%u' size=16 maxlength=10 "
		,LANG_FT_tCultivoPB_uCultivoPB,uCultivoPB);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCultivoPB value='%u' >\n",uCultivoPB);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tCultivoPB_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tCultivoPB_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//cBacteria uRADType=253
	OpenRow(LANG_FL_tCultivoPB_cBacteria,"black");
	printf("<input title='%s' type=text name=cBacteria value='%s' size=40 maxlength=65 "
		,LANG_FT_tCultivoPB_cBacteria,EncodeDoubleQuotes(cBacteria));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cBacteria value='%s'>\n",EncodeDoubleQuotes(cBacteria));
	}
	//cSensibilidad COLTYPE_TEXT
	OpenRow(LANG_FL_tCultivoPB_cSensibilidad,"black");
	printf("<textarea title='%s' cols=40 wrap=hard rows=1 name=cSensibilidad "
,LANG_FT_tCultivoPB_cSensibilidad);
	if(guPermLevel>=0 && uMode)
	{
		printf(">%s</textarea></td></tr>\n",cSensibilidad);
	}
	else
	{
		printf("disabled>%s</textarea></td></tr>\n",cSensibilidad);
		printf("<input type=hidden name=cSensibilidad value=\"%s\" >\n",EncodeDoubleQuotes(cSensibilidad));
	}
	//cResistencia COLTYPE_TEXT
	OpenRow(LANG_FL_tCultivoPB_cResistencia,"black");
	printf("<textarea title='%s' cols=40 wrap=hard rows=1 name=cResistencia "
,LANG_FT_tCultivoPB_cResistencia);
	if(guPermLevel>=0 && uMode)
	{
		printf(">%s</textarea></td></tr>\n",cResistencia);
	}
	else
	{
		printf("disabled>%s</textarea></td></tr>\n",cResistencia);
		printf("<input type=hidden name=cResistencia value=\"%s\" >\n",EncodeDoubleQuotes(cResistencia));
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tCultivoPB_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tCultivoPB_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tCultivoPB_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tCultivoPB_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tCultivoPB_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tCultivoPBInput(unsigned uMode)


void tCultivoPB(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttCultivoPBSelectRow();
		else
			ExttCultivoPBSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetCultivoPB();
				unxsSalud("New tCultivoPB table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tCultivoPB WHERE uCultivoPB=%u"
						,uCultivoPB);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uCultivoPB);
		sprintf(cLabel,"%.32s",field[1]);
		sprintf(cBacteria,"%.65s",field[2]);
		cSensibilidad=field[3];
		cResistencia=field[4];
		sscanf(field[5],"%u",&uOwner);
		sscanf(field[6],"%u",&uCreatedBy);
		sscanf(field[7],"%lu",&uCreatedDate);
		sscanf(field[8],"%u",&uModBy);
		sscanf(field[9],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Cultivo PB",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tCultivoPBTools>");
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

        ExttCultivoPBButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tCultivoPB Record Data",100);

	if(guMode==2000 || guMode==2002)
		tCultivoPBInput(1);
	else
		tCultivoPBInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttCultivoPBAuxTable();

	FooterRAD4();

}//end of tCultivoPB();


void NewtCultivoPB(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uCultivoPB FROM tCultivoPB WHERE uCultivoPB=%u",uCultivoPB);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tCultivoPB(LANG_NBR_RECEXISTS);

	Insert_tCultivoPB();
	uCultivoPB=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tCultivoPB",uCultivoPB);
	unxsSaludLog(uCultivoPB,"tCultivoPB","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uCultivoPB);
		tCultivoPB(gcQuery);
	}

}//NewtCultivoPB(unsigned uMode)


void DeletetCultivoPB(void)
{
	sprintf(gcQuery,"DELETE FROM tCultivoPB WHERE uCultivoPB=%u AND ( uOwner=%u OR %u>9 )"
					,uCultivoPB,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uCultivoPB,"tCultivoPB","Del");
		tCultivoPB(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uCultivoPB,"tCultivoPB","DelError");
		tCultivoPB(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetCultivoPB(void)


void Insert_tCultivoPB(void)
{
	sprintf(gcQuery,"INSERT INTO tCultivoPB SET "
		"cLabel='%s',"
		"cBacteria='%s',"
		"cSensibilidad='%s',"
		"cResistencia='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,TextAreaSave(cBacteria)
			,TextAreaSave(cSensibilidad)
			,TextAreaSave(cResistencia)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tCultivoPB(void)


void Update_tCultivoPB(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tCultivoPB SET "
		"cLabel='%s',"
		"cBacteria='%s',"
		"cSensibilidad='%s',"
		"cResistencia='%s',"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,TextAreaSave(cBacteria)
			,TextAreaSave(cSensibilidad)
			,TextAreaSave(cResistencia)
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tCultivoPB(void)


void ModtCultivoPB(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tCultivoPB.uCultivoPB,"
				" tCultivoPB.uModDate"
				" FROM tCultivoPB,tClient"
				" WHERE tCultivoPB.uCultivoPB=%u"
				" AND tCultivoPB.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uCultivoPB,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uCultivoPB,uModDate FROM tCultivoPB"
				" WHERE uCultivoPB=%u"
					,uCultivoPB);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tCultivoPB(LANG_NBR_RECNOTEXIST);
	if(i>1) tCultivoPB(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tCultivoPB(LANG_NBR_EXTMOD);

	Update_tCultivoPB(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tCultivoPB",uCultivoPB);
	unxsSaludLog(uCultivoPB,"tCultivoPB","Mod");
	tCultivoPB(gcQuery);

}//ModtCultivoPB(void)


void tCultivoPBList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttCultivoPBListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tCultivoPBList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttCultivoPBListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uCultivoPB"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>cBacteria"
		"<td><font face=arial,helvetica color=white>cSensibilidad"
		"<td><font face=arial,helvetica color=white>cResistencia"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tCultivoPB&uCultivoPB=%s>%s</a><td>%s<td>%s<td><textarea disabled>%s</textarea><td><textarea disabled>%s</textarea><td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,field[2]
			,field[3]
			,field[4]
			,cBuf5
			,cBuf6
			,cBuf7
			,cBuf8
			,cBuf9
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tCultivoPBList()


void CreatetCultivoPB(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tCultivoPB ("
		"uCultivoPB INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"cBacteria VARCHAR(65) NOT NULL DEFAULT '',"
		"cSensibilidad TEXT NOT NULL DEFAULT '',"
		"cResistencia TEXT NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetCultivoPB(void)



