/*
FILE
	tinternacion.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tinternacionfunc.h
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
static unsigned uInternacion=0;
static char cLabel[33]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tInternacion "tInternacion.uInternacion,tInternacion.cLabel,tInternacion.uOwner,tInternacion.uCreatedBy,tInternacion.uCreatedDate,tInternacion.uModBy,tInternacion.uModDate"

 //Local only
void Insert_tInternacion(void);
void Update_tInternacion(char *cRowid);
void ProcesstInternacionListVars(pentry entries[], int x);

 //In tInternacionfunc.h file included below
void ExtProcesstInternacionVars(pentry entries[], int x);
void ExttInternacionCommands(pentry entries[], int x);
void ExttInternacionButtons(void);
void ExttInternacionNavBar(void);
void ExttInternacionGetHook(entry gentries[], int x);
void ExttInternacionSelect(void);
void ExttInternacionSelectRow(void);
void ExttInternacionListSelect(void);
void ExttInternacionListFilter(void);
void ExttInternacionAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tinternacionfunc.h"

 //Table Variables Assignment Function
void ProcesstInternacionVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uInternacion"))
			sscanf(entries[i].val,"%u",&uInternacion);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
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
	ExtProcesstInternacionVars(entries,x);

}//ProcesstInternacionVars()


void ProcesstInternacionListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstInternacionListVars(pentry entries[], int x)


int tInternacionCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttInternacionCommands(entries,x);

	if(!strcmp(gcFunction,"tInternacionTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tInternacionList();
		}

		//Default
		ProcesstInternacionVars(entries,x);
		tInternacion("");
	}
	else if(!strcmp(gcFunction,"tInternacionList"))
	{
		ProcessControlVars(entries,x);
		ProcesstInternacionListVars(entries,x);
		tInternacionList();
	}

	return(0);

}//tInternacionCommands()


void tInternacionInput(unsigned uMode)
{
	
	//uInternacion uRADType=1001
	OpenRow(LANG_FL_tInternacion_uInternacion,"black");
	printf("<input title='%s' type=text name=uInternacion value='%u' size=16 maxlength=10 "
		,LANG_FT_tInternacion_uInternacion,uInternacion);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uInternacion value='%u' >\n",uInternacion);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tInternacion_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tInternacion_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInternacion_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInternacion_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tInternacion_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInternacion_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tInternacion_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tInternacionInput(unsigned uMode)


void tInternacion(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttInternacionSelectRow();
		else
			ExttInternacionSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetInternacion();
				unxsSalud("New tInternacion table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tInternacion WHERE uInternacion=%u"
						,uInternacion);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uInternacion);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uOwner);
		sscanf(field[3],"%u",&uCreatedBy);
		sscanf(field[4],"%lu",&uCreatedDate);
		sscanf(field[5],"%u",&uModBy);
		sscanf(field[6],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Internacion",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tInternacionTools>");
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

        ExttInternacionButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tInternacion Record Data",100);

	if(guMode==2000 || guMode==2002)
		tInternacionInput(1);
	else
		tInternacionInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttInternacionAuxTable();

	FooterRAD4();

}//end of tInternacion();


void NewtInternacion(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uInternacion FROM tInternacion WHERE uInternacion=%u",uInternacion);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tInternacion(LANG_NBR_RECEXISTS);

	Insert_tInternacion();
	uInternacion=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tInternacion",uInternacion);
	unxsSaludLog(uInternacion,"tInternacion","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uInternacion);
		tInternacion(gcQuery);
	}

}//NewtInternacion(unsigned uMode)


void DeletetInternacion(void)
{
	sprintf(gcQuery,"DELETE FROM tInternacion WHERE uInternacion=%u AND ( uOwner=%u OR %u>9 )"
					,uInternacion,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uInternacion,"tInternacion","Del");
		tInternacion(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uInternacion,"tInternacion","DelError");
		tInternacion(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetInternacion(void)


void Insert_tInternacion(void)
{
	sprintf(gcQuery,"INSERT INTO tInternacion SET "
		"cLabel='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tInternacion(void)


void Update_tInternacion(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tInternacion SET "
		"cLabel='%s',"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tInternacion(void)


void ModtInternacion(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tInternacion.uInternacion,"
				" tInternacion.uModDate"
				" FROM tInternacion,tClient"
				" WHERE tInternacion.uInternacion=%u"
				" AND tInternacion.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uInternacion,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uInternacion,uModDate FROM tInternacion"
				" WHERE uInternacion=%u"
					,uInternacion);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tInternacion(LANG_NBR_RECNOTEXIST);
	if(i>1) tInternacion(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tInternacion(LANG_NBR_EXTMOD);

	Update_tInternacion(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tInternacion",uInternacion);
	unxsSaludLog(uInternacion,"tInternacion","Mod");
	tInternacion(gcQuery);

}//ModtInternacion(void)


void tInternacionList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttInternacionListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tInternacionList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttInternacionListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uInternacion"
		"<td><font face=arial,helvetica color=white>cLabel"
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
		sprintf(cBuf2,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[2],
			ForeignKey("tClient","cLabel",strtoul(field[2],NULL,10)));
		char cBuf3[128];
		sprintf(cBuf3,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[3],
			ForeignKey("tClient","cLabel",strtoul(field[3],NULL,10)));
		time_t luTime4=strtoul(field[4],NULL,10);
		char cBuf4[32];
		if(luTime4)
			ctime_r(&luTime4,cBuf4);
		else
			sprintf(cBuf4,"---");
		char cBuf5[128];
		sprintf(cBuf5,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[5],
			ForeignKey("tClient","cLabel",strtoul(field[5],NULL,10)));
		time_t luTime6=strtoul(field[6],NULL,10);
		char cBuf6[32];
		if(luTime6)
			ctime_r(&luTime6,cBuf6);
		else
			sprintf(cBuf6,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tInternacion&uInternacion=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,cBuf2
			,cBuf3
			,cBuf4
			,cBuf5
			,cBuf6
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tInternacionList()


void CreatetInternacion(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tInternacion ("
		"uInternacion INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetInternacion(void)



