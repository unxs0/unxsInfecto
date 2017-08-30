/*
FILE
	tcentro.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tcentrofunc.h
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
static unsigned uCentro=0;
static char cLabel[33]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tCentro "tCentro.uCentro,tCentro.cLabel,tCentro.uOwner,tCentro.uCreatedBy,tCentro.uCreatedDate,tCentro.uModBy,tCentro.uModDate"

 //Local only
void Insert_tCentro(void);
void Update_tCentro(char *cRowid);
void ProcesstCentroListVars(pentry entries[], int x);

 //In tCentrofunc.h file included below
void ExtProcesstCentroVars(pentry entries[], int x);
void ExttCentroCommands(pentry entries[], int x);
void ExttCentroButtons(void);
void ExttCentroNavBar(void);
void ExttCentroGetHook(entry gentries[], int x);
void ExttCentroSelect(void);
void ExttCentroSelectRow(void);
void ExttCentroListSelect(void);
void ExttCentroListFilter(void);
void ExttCentroAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tcentrofunc.h"

 //Table Variables Assignment Function
void ProcesstCentroVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uCentro"))
			sscanf(entries[i].val,"%u",&uCentro);
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
	ExtProcesstCentroVars(entries,x);

}//ProcesstCentroVars()


void ProcesstCentroListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstCentroListVars(pentry entries[], int x)


int tCentroCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttCentroCommands(entries,x);

	if(!strcmp(gcFunction,"tCentroTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tCentroList();
		}

		//Default
		ProcesstCentroVars(entries,x);
		tCentro("");
	}
	else if(!strcmp(gcFunction,"tCentroList"))
	{
		ProcessControlVars(entries,x);
		ProcesstCentroListVars(entries,x);
		tCentroList();
	}

	return(0);

}//tCentroCommands()


void tCentroInput(unsigned uMode)
{
	
	//uCentro uRADType=1001
	OpenRow(LANG_FL_tCentro_uCentro,"black");
	printf("<input title='%s' type=text name=uCentro value='%u' size=16 maxlength=10 "
		,LANG_FT_tCentro_uCentro,uCentro);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCentro value='%u' >\n",uCentro);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tCentro_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tCentro_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tCentro_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tCentro_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tCentro_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tCentro_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tCentro_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tCentroInput(unsigned uMode)


void tCentro(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttCentroSelectRow();
		else
			ExttCentroSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetCentro();
				unxsSalud("New tCentro table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tCentro WHERE uCentro=%u"
						,uCentro);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uCentro);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uOwner);
		sscanf(field[3],"%u",&uCreatedBy);
		sscanf(field[4],"%lu",&uCreatedDate);
		sscanf(field[5],"%u",&uModBy);
		sscanf(field[6],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de centros medicos",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tCentroTools>");
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

        ExttCentroButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tCentro Record Data",100);

	if(guMode==2000 || guMode==2002)
		tCentroInput(1);
	else
		tCentroInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttCentroAuxTable();

	FooterRAD4();

}//end of tCentro();


void NewtCentro(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uCentro FROM tCentro WHERE uCentro=%u",uCentro);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tCentro(LANG_NBR_RECEXISTS);

	Insert_tCentro();
	uCentro=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tCentro",uCentro);
	unxsSaludLog(uCentro,"tCentro","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uCentro);
		tCentro(gcQuery);
	}

}//NewtCentro(unsigned uMode)


void DeletetCentro(void)
{
	sprintf(gcQuery,"DELETE FROM tCentro WHERE uCentro=%u AND ( uOwner=%u OR %u>9 )"
					,uCentro,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uCentro,"tCentro","Del");
		tCentro(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uCentro,"tCentro","DelError");
		tCentro(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetCentro(void)


void Insert_tCentro(void)
{
	sprintf(gcQuery,"INSERT INTO tCentro SET "
		"cLabel='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tCentro(void)


void Update_tCentro(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tCentro SET "
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

}//void Update_tCentro(void)


void ModtCentro(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tCentro.uCentro,"
				" tCentro.uModDate"
				" FROM tCentro,tClient"
				" WHERE tCentro.uCentro=%u"
				" AND tCentro.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uCentro,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uCentro,uModDate FROM tCentro"
				" WHERE uCentro=%u"
					,uCentro);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tCentro(LANG_NBR_RECNOTEXIST);
	if(i>1) tCentro(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tCentro(LANG_NBR_EXTMOD);

	Update_tCentro(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tCentro",uCentro);
	unxsSaludLog(uCentro,"tCentro","Mod");
	tCentro(gcQuery);

}//ModtCentro(void)


void tCentroList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttCentroListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tCentroList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttCentroListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uCentro"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tCentro&uCentro=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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

}//tCentroList()


void CreatetCentro(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tCentro ("
		"uCentro INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetCentro(void)



