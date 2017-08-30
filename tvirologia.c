/*
FILE
	tvirologia.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tvirologiafunc.h
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
static unsigned uVirologia=0;
static char cLabel[33]={""};
static unsigned uHIV=0;
static unsigned uHVB=0;
static unsigned uHVC=0;
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tVirologia "tVirologia.uVirologia,tVirologia.cLabel,tVirologia.uHIV,tVirologia.uHVB,tVirologia.uHVC,tVirologia.uOwner,tVirologia.uCreatedBy,tVirologia.uCreatedDate,tVirologia.uModBy,tVirologia.uModDate"

 //Local only
void Insert_tVirologia(void);
void Update_tVirologia(char *cRowid);
void ProcesstVirologiaListVars(pentry entries[], int x);

 //In tVirologiafunc.h file included below
void ExtProcesstVirologiaVars(pentry entries[], int x);
void ExttVirologiaCommands(pentry entries[], int x);
void ExttVirologiaButtons(void);
void ExttVirologiaNavBar(void);
void ExttVirologiaGetHook(entry gentries[], int x);
void ExttVirologiaSelect(void);
void ExttVirologiaSelectRow(void);
void ExttVirologiaListSelect(void);
void ExttVirologiaListFilter(void);
void ExttVirologiaAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tvirologiafunc.h"

 //Table Variables Assignment Function
void ProcesstVirologiaVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uVirologia"))
			sscanf(entries[i].val,"%u",&uVirologia);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uHIV"))
			sscanf(entries[i].val,"%u",&uHIV);
		else if(!strcmp(entries[i].name,"uHVB"))
			sscanf(entries[i].val,"%u",&uHVB);
		else if(!strcmp(entries[i].name,"uHVC"))
			sscanf(entries[i].val,"%u",&uHVC);
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
	ExtProcesstVirologiaVars(entries,x);

}//ProcesstVirologiaVars()


void ProcesstVirologiaListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstVirologiaListVars(pentry entries[], int x)


int tVirologiaCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttVirologiaCommands(entries,x);

	if(!strcmp(gcFunction,"tVirologiaTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tVirologiaList();
		}

		//Default
		ProcesstVirologiaVars(entries,x);
		tVirologia("");
	}
	else if(!strcmp(gcFunction,"tVirologiaList"))
	{
		ProcessControlVars(entries,x);
		ProcesstVirologiaListVars(entries,x);
		tVirologiaList();
	}

	return(0);

}//tVirologiaCommands()


void tVirologiaInput(unsigned uMode)
{
	
	//uVirologia uRADType=1001
	OpenRow(LANG_FL_tVirologia_uVirologia,"black");
	printf("<input title='%s' type=text name=uVirologia value='%u' size=16 maxlength=10 "
		,LANG_FT_tVirologia_uVirologia,uVirologia);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uVirologia value='%u' >\n",uVirologia);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tVirologia_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tVirologia_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uHIV uRADType=3
	OpenRow(LANG_FL_tVirologia_uHIV,"black");
	printf("<input title='%s' type=text name=uHIV value='%u' size=16 maxlength=10 "
		,LANG_FT_tVirologia_uHIV,uHIV);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHIV value='%u' >\n",uHIV);
	}
	//uHVB uRADType=3
	OpenRow(LANG_FL_tVirologia_uHVB,"black");
	printf("<input title='%s' type=text name=uHVB value='%u' size=16 maxlength=10 "
		,LANG_FT_tVirologia_uHVB,uHVB);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVB value='%u' >\n",uHVB);
	}
	//uHVC uRADType=3
	OpenRow(LANG_FL_tVirologia_uHVC,"black");
	printf("<input title='%s' type=text name=uHVC value='%u' size=16 maxlength=10 "
		,LANG_FT_tVirologia_uHVC,uHVC);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVC value='%u' >\n",uHVC);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVirologia_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVirologia_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tVirologia_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVirologia_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tVirologia_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tVirologiaInput(unsigned uMode)


void tVirologia(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttVirologiaSelectRow();
		else
			ExttVirologiaSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetVirologia();
				unxsSalud("New tVirologia table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tVirologia WHERE uVirologia=%u"
						,uVirologia);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uVirologia);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uHIV);
		sscanf(field[3],"%u",&uHVB);
		sscanf(field[4],"%u",&uHVC);
		sscanf(field[5],"%u",&uOwner);
		sscanf(field[6],"%u",&uCreatedBy);
		sscanf(field[7],"%lu",&uCreatedDate);
		sscanf(field[8],"%u",&uModBy);
		sscanf(field[9],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Virologia",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tVirologiaTools>");
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

        ExttVirologiaButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tVirologia Record Data",100);

	if(guMode==2000 || guMode==2002)
		tVirologiaInput(1);
	else
		tVirologiaInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttVirologiaAuxTable();

	FooterRAD4();

}//end of tVirologia();


void NewtVirologia(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uVirologia FROM tVirologia WHERE uVirologia=%u",uVirologia);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tVirologia(LANG_NBR_RECEXISTS);

	Insert_tVirologia();
	uVirologia=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tVirologia",uVirologia);
	unxsSaludLog(uVirologia,"tVirologia","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uVirologia);
		tVirologia(gcQuery);
	}

}//NewtVirologia(unsigned uMode)


void DeletetVirologia(void)
{
	sprintf(gcQuery,"DELETE FROM tVirologia WHERE uVirologia=%u AND ( uOwner=%u OR %u>9 )"
					,uVirologia,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uVirologia,"tVirologia","Del");
		tVirologia(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uVirologia,"tVirologia","DelError");
		tVirologia(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetVirologia(void)


void Insert_tVirologia(void)
{
	sprintf(gcQuery,"INSERT INTO tVirologia SET "
		"cLabel='%s',"
		"uHIV=%u,"
		"uHVB=%u,"
		"uHVC=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uHIV
			,uHVB
			,uHVC
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tVirologia(void)


void Update_tVirologia(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tVirologia SET "
		"cLabel='%s',"
		"uHIV=%u,"
		"uHVB=%u,"
		"uHVC=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uHIV
			,uHVB
			,uHVC
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tVirologia(void)


void ModtVirologia(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tVirologia.uVirologia,"
				" tVirologia.uModDate"
				" FROM tVirologia,tClient"
				" WHERE tVirologia.uVirologia=%u"
				" AND tVirologia.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uVirologia,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uVirologia,uModDate FROM tVirologia"
				" WHERE uVirologia=%u"
					,uVirologia);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tVirologia(LANG_NBR_RECNOTEXIST);
	if(i>1) tVirologia(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tVirologia(LANG_NBR_EXTMOD);

	Update_tVirologia(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tVirologia",uVirologia);
	unxsSaludLog(uVirologia,"tVirologia","Mod");
	tVirologia(gcQuery);

}//ModtVirologia(void)


void tVirologiaList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttVirologiaListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tVirologiaList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttVirologiaListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uVirologia"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uHIV"
		"<td><font face=arial,helvetica color=white>uHVB"
		"<td><font face=arial,helvetica color=white>uHVC"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tVirologia&uVirologia=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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

}//tVirologiaList()


void CreatetVirologia(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tVirologia ("
		"uVirologia INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uHIV INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVB INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVC INT UNSIGNED NOT NULL DEFAULT 0,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetVirologia(void)



