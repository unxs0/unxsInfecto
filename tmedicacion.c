/*
FILE
	tmedicacion.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tmedicacionfunc.h
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
static unsigned uMedicacion=0;
static char cLabel[33]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tMedicacion "tMedicacion.uMedicacion,tMedicacion.cLabel,tMedicacion.uOwner,tMedicacion.uCreatedBy,tMedicacion.uCreatedDate,tMedicacion.uModBy,tMedicacion.uModDate"

 //Local only
void Insert_tMedicacion(void);
void Update_tMedicacion(char *cRowid);
void ProcesstMedicacionListVars(pentry entries[], int x);

 //In tMedicacionfunc.h file included below
void ExtProcesstMedicacionVars(pentry entries[], int x);
void ExttMedicacionCommands(pentry entries[], int x);
void ExttMedicacionButtons(void);
void ExttMedicacionNavBar(void);
void ExttMedicacionGetHook(entry gentries[], int x);
void ExttMedicacionSelect(void);
void ExttMedicacionSelectRow(void);
void ExttMedicacionListSelect(void);
void ExttMedicacionListFilter(void);
void ExttMedicacionAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tmedicacionfunc.h"

 //Table Variables Assignment Function
void ProcesstMedicacionVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uMedicacion"))
			sscanf(entries[i].val,"%u",&uMedicacion);
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
	ExtProcesstMedicacionVars(entries,x);

}//ProcesstMedicacionVars()


void ProcesstMedicacionListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstMedicacionListVars(pentry entries[], int x)


int tMedicacionCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttMedicacionCommands(entries,x);

	if(!strcmp(gcFunction,"tMedicacionTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tMedicacionList();
		}

		//Default
		ProcesstMedicacionVars(entries,x);
		tMedicacion("");
	}
	else if(!strcmp(gcFunction,"tMedicacionList"))
	{
		ProcessControlVars(entries,x);
		ProcesstMedicacionListVars(entries,x);
		tMedicacionList();
	}

	return(0);

}//tMedicacionCommands()


void tMedicacionInput(unsigned uMode)
{
	
	//uMedicacion uRADType=1001
	OpenRow(LANG_FL_tMedicacion_uMedicacion,"black");
	printf("<input title='%s' type=text name=uMedicacion value='%u' size=16 maxlength=10 "
		,LANG_FT_tMedicacion_uMedicacion,uMedicacion);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uMedicacion value='%u' >\n",uMedicacion);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tMedicacion_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tMedicacion_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tMedicacion_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMedicacion_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMedicacion_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMedicacion_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMedicacion_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tMedicacionInput(unsigned uMode)


void tMedicacion(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttMedicacionSelectRow();
		else
			ExttMedicacionSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetMedicacion();
				unxsSalud("New tMedicacion table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tMedicacion WHERE uMedicacion=%u"
						,uMedicacion);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uMedicacion);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uOwner);
		sscanf(field[3],"%u",&uCreatedBy);
		sscanf(field[4],"%lu",&uCreatedDate);
		sscanf(field[5],"%u",&uModBy);
		sscanf(field[6],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Medicación",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tMedicacionTools>");
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

        ExttMedicacionButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tMedicacion Record Data",100);

	if(guMode==2000 || guMode==2002)
		tMedicacionInput(1);
	else
		tMedicacionInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttMedicacionAuxTable();

	FooterRAD4();

}//end of tMedicacion();


void NewtMedicacion(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uMedicacion FROM tMedicacion WHERE uMedicacion=%u",uMedicacion);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tMedicacion(LANG_NBR_RECEXISTS);

	Insert_tMedicacion();
	uMedicacion=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tMedicacion",uMedicacion);
	unxsSaludLog(uMedicacion,"tMedicacion","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uMedicacion);
		tMedicacion(gcQuery);
	}

}//NewtMedicacion(unsigned uMode)


void DeletetMedicacion(void)
{
	sprintf(gcQuery,"DELETE FROM tMedicacion WHERE uMedicacion=%u AND ( uOwner=%u OR %u>9 )"
					,uMedicacion,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uMedicacion,"tMedicacion","Del");
		tMedicacion(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uMedicacion,"tMedicacion","DelError");
		tMedicacion(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetMedicacion(void)


void Insert_tMedicacion(void)
{
	sprintf(gcQuery,"INSERT INTO tMedicacion SET "
		"cLabel='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tMedicacion(void)


void Update_tMedicacion(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tMedicacion SET "
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

}//void Update_tMedicacion(void)


void ModtMedicacion(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tMedicacion.uMedicacion,"
				" tMedicacion.uModDate"
				" FROM tMedicacion,tClient"
				" WHERE tMedicacion.uMedicacion=%u"
				" AND tMedicacion.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uMedicacion,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uMedicacion,uModDate FROM tMedicacion"
				" WHERE uMedicacion=%u"
					,uMedicacion);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tMedicacion(LANG_NBR_RECNOTEXIST);
	if(i>1) tMedicacion(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tMedicacion(LANG_NBR_EXTMOD);

	Update_tMedicacion(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tMedicacion",uMedicacion);
	unxsSaludLog(uMedicacion,"tMedicacion","Mod");
	tMedicacion(gcQuery);

}//ModtMedicacion(void)


void tMedicacionList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttMedicacionListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tMedicacionList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttMedicacionListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uMedicacion"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tMedicacion&uMedicacion=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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

}//tMedicacionList()


void CreatetMedicacion(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tMedicacion ("
		"uMedicacion INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetMedicacion(void)



