/*
FILE
	tinmunizacion.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tinmunizacionfunc.h
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
static unsigned uInmunizacion=0;
static char cLabel[33]={""};
static char uFecha[20]={"2000-01-01 00:00:00"};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tInmunizacion "tInmunizacion.uInmunizacion,tInmunizacion.cLabel,tInmunizacion.uFecha,tInmunizacion.uOwner,tInmunizacion.uCreatedBy,tInmunizacion.uCreatedDate,tInmunizacion.uModBy,tInmunizacion.uModDate"

 //Local only
void Insert_tInmunizacion(void);
void Update_tInmunizacion(char *cRowid);
void ProcesstInmunizacionListVars(pentry entries[], int x);

 //In tInmunizacionfunc.h file included below
void ExtProcesstInmunizacionVars(pentry entries[], int x);
void ExttInmunizacionCommands(pentry entries[], int x);
void ExttInmunizacionButtons(void);
void ExttInmunizacionNavBar(void);
void ExttInmunizacionGetHook(entry gentries[], int x);
void ExttInmunizacionSelect(void);
void ExttInmunizacionSelectRow(void);
void ExttInmunizacionListSelect(void);
void ExttInmunizacionListFilter(void);
void ExttInmunizacionAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tinmunizacionfunc.h"

 //Table Variables Assignment Function
void ProcesstInmunizacionVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uInmunizacion"))
			sscanf(entries[i].val,"%u",&uInmunizacion);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uFecha"))
			sprintf(uFecha,"%.10s",entries[i].val);
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
	ExtProcesstInmunizacionVars(entries,x);

}//ProcesstInmunizacionVars()


void ProcesstInmunizacionListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstInmunizacionListVars(pentry entries[], int x)


int tInmunizacionCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttInmunizacionCommands(entries,x);

	if(!strcmp(gcFunction,"tInmunizacionTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tInmunizacionList();
		}

		//Default
		ProcesstInmunizacionVars(entries,x);
		tInmunizacion("");
	}
	else if(!strcmp(gcFunction,"tInmunizacionList"))
	{
		ProcessControlVars(entries,x);
		ProcesstInmunizacionListVars(entries,x);
		tInmunizacionList();
	}

	return(0);

}//tInmunizacionCommands()


void tInmunizacionInput(unsigned uMode)
{
	
	//uInmunizacion uRADType=1001
	OpenRow(LANG_FL_tInmunizacion_uInmunizacion,"black");
	printf("<input title='%s' type=text name=uInmunizacion value='%u' size=16 maxlength=10 "
		,LANG_FT_tInmunizacion_uInmunizacion,uInmunizacion);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uInmunizacion value='%u' >\n",uInmunizacion);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tInmunizacion_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tInmunizacion_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uFecha COLTYPE_DATETIME
	OpenRow(LANG_FL_tInmunizacion_uFecha,"black");
	if(guPermLevel>=7 && uMode)
		jsCalendarInput("uFecha",EncodeDoubleQuotes(uFecha),1);
	else
		jsCalendarInput("uFecha",EncodeDoubleQuotes(uFecha),0);
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInmunizacion_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInmunizacion_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tInmunizacion_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tInmunizacion_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tInmunizacion_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tInmunizacionInput(unsigned uMode)


void tInmunizacion(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttInmunizacionSelectRow();
		else
			ExttInmunizacionSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetInmunizacion();
				unxsSalud("New tInmunizacion table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tInmunizacion WHERE uInmunizacion=%u"
						,uInmunizacion);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uInmunizacion);
		sprintf(cLabel,"%.32s",field[1]);
		sprintf(uFecha,"%.10s",field[2]);
		sscanf(field[3],"%u",&uOwner);
		sscanf(field[4],"%u",&uCreatedBy);
		sscanf(field[5],"%lu",&uCreatedDate);
		sscanf(field[6],"%u",&uModBy);
		sscanf(field[7],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Inmunizaciones",1);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tInmunizacionTools>");
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

        ExttInmunizacionButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tInmunizacion Record Data",100);

	if(guMode==2000 || guMode==2002)
		tInmunizacionInput(1);
	else
		tInmunizacionInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttInmunizacionAuxTable();

	FooterRAD4();

}//end of tInmunizacion();


void NewtInmunizacion(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uInmunizacion FROM tInmunizacion WHERE uInmunizacion=%u",uInmunizacion);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tInmunizacion(LANG_NBR_RECEXISTS);

	Insert_tInmunizacion();
	uInmunizacion=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tInmunizacion",uInmunizacion);
	unxsSaludLog(uInmunizacion,"tInmunizacion","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uInmunizacion);
		tInmunizacion(gcQuery);
	}

}//NewtInmunizacion(unsigned uMode)


void DeletetInmunizacion(void)
{
	sprintf(gcQuery,"DELETE FROM tInmunizacion WHERE uInmunizacion=%u AND ( uOwner=%u OR %u>9 )"
					,uInmunizacion,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uInmunizacion,"tInmunizacion","Del");
		tInmunizacion(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uInmunizacion,"tInmunizacion","DelError");
		tInmunizacion(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetInmunizacion(void)


void Insert_tInmunizacion(void)
{
	sprintf(gcQuery,"INSERT INTO tInmunizacion SET "
		"cLabel='%s',"
		"uFecha='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,TextAreaSave(uFecha)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tInmunizacion(void)


void Update_tInmunizacion(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tInmunizacion SET "
		"cLabel='%s',"
		"uFecha='%s',"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,TextAreaSave(uFecha)
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tInmunizacion(void)


void ModtInmunizacion(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tInmunizacion.uInmunizacion,"
				" tInmunizacion.uModDate"
				" FROM tInmunizacion,tClient"
				" WHERE tInmunizacion.uInmunizacion=%u"
				" AND tInmunizacion.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uInmunizacion,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uInmunizacion,uModDate FROM tInmunizacion"
				" WHERE uInmunizacion=%u"
					,uInmunizacion);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tInmunizacion(LANG_NBR_RECNOTEXIST);
	if(i>1) tInmunizacion(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tInmunizacion(LANG_NBR_EXTMOD);

	Update_tInmunizacion(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tInmunizacion",uInmunizacion);
	unxsSaludLog(uInmunizacion,"tInmunizacion","Mod");
	tInmunizacion(gcQuery);

}//ModtInmunizacion(void)


void tInmunizacionList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttInmunizacionListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tInmunizacionList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttInmunizacionListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uInmunizacion"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uFecha"
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
				char cBuf3[128];
		sprintf(cBuf3,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[3],
			ForeignKey("tClient","cLabel",strtoul(field[3],NULL,10)));
		char cBuf4[128];
		sprintf(cBuf4,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[4],
			ForeignKey("tClient","cLabel",strtoul(field[4],NULL,10)));
		time_t luTime5=strtoul(field[5],NULL,10);
		char cBuf5[32];
		if(luTime5)
			ctime_r(&luTime5,cBuf5);
		else
			sprintf(cBuf5,"---");
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tInmunizacion&uInmunizacion=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,field[2]
			,cBuf3
			,cBuf4
			,cBuf5
			,cBuf6
			,cBuf7
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tInmunizacionList()


void CreatetInmunizacion(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tInmunizacion ("
		"uInmunizacion INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uFecha DATETIME NOT NULL,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetInmunizacion(void)



