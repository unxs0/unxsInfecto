/*
FILE
	turocultivo.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in turocultivofunc.h
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
static unsigned uUrocultivo=0;
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


#define VAR_LIST_tUrocultivo "tUrocultivo.uUrocultivo,tUrocultivo.cLabel,tUrocultivo.cBacteria,tUrocultivo.cSensibilidad,tUrocultivo.cResistencia,tUrocultivo.uOwner,tUrocultivo.uCreatedBy,tUrocultivo.uCreatedDate,tUrocultivo.uModBy,tUrocultivo.uModDate"

 //Local only
void Insert_tUrocultivo(void);
void Update_tUrocultivo(char *cRowid);
void ProcesstUrocultivoListVars(pentry entries[], int x);

 //In tUrocultivofunc.h file included below
void ExtProcesstUrocultivoVars(pentry entries[], int x);
void ExttUrocultivoCommands(pentry entries[], int x);
void ExttUrocultivoButtons(void);
void ExttUrocultivoNavBar(void);
void ExttUrocultivoGetHook(entry gentries[], int x);
void ExttUrocultivoSelect(void);
void ExttUrocultivoSelectRow(void);
void ExttUrocultivoListSelect(void);
void ExttUrocultivoListFilter(void);
void ExttUrocultivoAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "turocultivofunc.h"

 //Table Variables Assignment Function
void ProcesstUrocultivoVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uUrocultivo"))
			sscanf(entries[i].val,"%u",&uUrocultivo);
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
	ExtProcesstUrocultivoVars(entries,x);

}//ProcesstUrocultivoVars()


void ProcesstUrocultivoListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstUrocultivoListVars(pentry entries[], int x)


int tUrocultivoCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttUrocultivoCommands(entries,x);

	if(!strcmp(gcFunction,"tUrocultivoTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tUrocultivoList();
		}

		//Default
		ProcesstUrocultivoVars(entries,x);
		tUrocultivo("");
	}
	else if(!strcmp(gcFunction,"tUrocultivoList"))
	{
		ProcessControlVars(entries,x);
		ProcesstUrocultivoListVars(entries,x);
		tUrocultivoList();
	}

	return(0);

}//tUrocultivoCommands()


void tUrocultivoInput(unsigned uMode)
{
	
	//uUrocultivo uRADType=1001
	OpenRow(LANG_FL_tUrocultivo_uUrocultivo,"black");
	printf("<input title='%s' type=text name=uUrocultivo value='%u' size=16 maxlength=10 "
		,LANG_FT_tUrocultivo_uUrocultivo,uUrocultivo);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uUrocultivo value='%u' >\n",uUrocultivo);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tUrocultivo_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tUrocultivo_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tUrocultivo_cBacteria,"black");
	printf("<input title='%s' type=text name=cBacteria value='%s' size=40 maxlength=65 "
		,LANG_FT_tUrocultivo_cBacteria,EncodeDoubleQuotes(cBacteria));
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
	OpenRow(LANG_FL_tUrocultivo_cSensibilidad,"black");
	printf("<textarea title='%s' cols=40 wrap=hard rows=1 name=cSensibilidad "
,LANG_FT_tUrocultivo_cSensibilidad);
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
	OpenRow(LANG_FL_tUrocultivo_cResistencia,"black");
	printf("<textarea title='%s' cols=40 wrap=hard rows=1 name=cResistencia "
,LANG_FT_tUrocultivo_cResistencia);
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
	OpenRow(LANG_FL_tUrocultivo_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tUrocultivo_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tUrocultivo_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tUrocultivo_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tUrocultivo_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tUrocultivoInput(unsigned uMode)


void tUrocultivo(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttUrocultivoSelectRow();
		else
			ExttUrocultivoSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetUrocultivo();
				unxsSalud("New tUrocultivo table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tUrocultivo WHERE uUrocultivo=%u"
						,uUrocultivo);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uUrocultivo);
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

	HeaderRAD4(":: Tabla de Urocultivo",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tUrocultivoTools>");
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

        ExttUrocultivoButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tUrocultivo Record Data",100);

	if(guMode==2000 || guMode==2002)
		tUrocultivoInput(1);
	else
		tUrocultivoInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttUrocultivoAuxTable();

	FooterRAD4();

}//end of tUrocultivo();


void NewtUrocultivo(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uUrocultivo FROM tUrocultivo WHERE uUrocultivo=%u",uUrocultivo);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tUrocultivo(LANG_NBR_RECEXISTS);

	Insert_tUrocultivo();
	uUrocultivo=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tUrocultivo",uUrocultivo);
	unxsSaludLog(uUrocultivo,"tUrocultivo","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uUrocultivo);
		tUrocultivo(gcQuery);
	}

}//NewtUrocultivo(unsigned uMode)


void DeletetUrocultivo(void)
{
	sprintf(gcQuery,"DELETE FROM tUrocultivo WHERE uUrocultivo=%u AND ( uOwner=%u OR %u>9 )"
					,uUrocultivo,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uUrocultivo,"tUrocultivo","Del");
		tUrocultivo(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uUrocultivo,"tUrocultivo","DelError");
		tUrocultivo(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetUrocultivo(void)


void Insert_tUrocultivo(void)
{
	sprintf(gcQuery,"INSERT INTO tUrocultivo SET "
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

}//void Insert_tUrocultivo(void)


void Update_tUrocultivo(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tUrocultivo SET "
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

}//void Update_tUrocultivo(void)


void ModtUrocultivo(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tUrocultivo.uUrocultivo,"
				" tUrocultivo.uModDate"
				" FROM tUrocultivo,tClient"
				" WHERE tUrocultivo.uUrocultivo=%u"
				" AND tUrocultivo.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uUrocultivo,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uUrocultivo,uModDate FROM tUrocultivo"
				" WHERE uUrocultivo=%u"
					,uUrocultivo);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tUrocultivo(LANG_NBR_RECNOTEXIST);
	if(i>1) tUrocultivo(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tUrocultivo(LANG_NBR_EXTMOD);

	Update_tUrocultivo(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tUrocultivo",uUrocultivo);
	unxsSaludLog(uUrocultivo,"tUrocultivo","Mod");
	tUrocultivo(gcQuery);

}//ModtUrocultivo(void)


void tUrocultivoList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttUrocultivoListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tUrocultivoList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttUrocultivoListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uUrocultivo"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tUrocultivo&uUrocultivo=%s>%s</a><td>%s<td>%s<td><textarea disabled>%s</textarea><td><textarea disabled>%s</textarea><td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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

}//tUrocultivoList()


void CreatetUrocultivo(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tUrocultivo ("
		"uUrocultivo INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
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
}//void CreatetUrocultivo(void)



