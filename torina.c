/*
FILE
	torina.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in torinafunc.h
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
static unsigned uOrina=0;
static char cLabel[33]={""};
static unsigned uLeucocitos=0;
static unsigned uPiocitos=0;
static unsigned uHematies=0;
static unsigned uCelulasEpiteliales=0;
static unsigned uGermenes=0;
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tOrina "tOrina.uOrina,tOrina.cLabel,tOrina.uLeucocitos,tOrina.uPiocitos,tOrina.uHematies,tOrina.uCelulasEpiteliales,tOrina.uGermenes,tOrina.uOwner,tOrina.uCreatedBy,tOrina.uCreatedDate,tOrina.uModBy,tOrina.uModDate"

 //Local only
void Insert_tOrina(void);
void Update_tOrina(char *cRowid);
void ProcesstOrinaListVars(pentry entries[], int x);

 //In tOrinafunc.h file included below
void ExtProcesstOrinaVars(pentry entries[], int x);
void ExttOrinaCommands(pentry entries[], int x);
void ExttOrinaButtons(void);
void ExttOrinaNavBar(void);
void ExttOrinaGetHook(entry gentries[], int x);
void ExttOrinaSelect(void);
void ExttOrinaSelectRow(void);
void ExttOrinaListSelect(void);
void ExttOrinaListFilter(void);
void ExttOrinaAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "torinafunc.h"

 //Table Variables Assignment Function
void ProcesstOrinaVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uOrina"))
			sscanf(entries[i].val,"%u",&uOrina);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uLeucocitos"))
			sscanf(entries[i].val,"%u",&uLeucocitos);
		else if(!strcmp(entries[i].name,"uPiocitos"))
			sscanf(entries[i].val,"%u",&uPiocitos);
		else if(!strcmp(entries[i].name,"uHematies"))
			sscanf(entries[i].val,"%u",&uHematies);
		else if(!strcmp(entries[i].name,"uCelulasEpiteliales"))
			sscanf(entries[i].val,"%u",&uCelulasEpiteliales);
		else if(!strcmp(entries[i].name,"uGermenes"))
			sscanf(entries[i].val,"%u",&uGermenes);
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
	ExtProcesstOrinaVars(entries,x);

}//ProcesstOrinaVars()


void ProcesstOrinaListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstOrinaListVars(pentry entries[], int x)


int tOrinaCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttOrinaCommands(entries,x);

	if(!strcmp(gcFunction,"tOrinaTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tOrinaList();
		}

		//Default
		ProcesstOrinaVars(entries,x);
		tOrina("");
	}
	else if(!strcmp(gcFunction,"tOrinaList"))
	{
		ProcessControlVars(entries,x);
		ProcesstOrinaListVars(entries,x);
		tOrinaList();
	}

	return(0);

}//tOrinaCommands()


void tOrinaInput(unsigned uMode)
{
	
	//uOrina uRADType=1001
	OpenRow(LANG_FL_tOrina_uOrina,"black");
	printf("<input title='%s' type=text name=uOrina value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uOrina,uOrina);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uOrina value='%u' >\n",uOrina);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tOrina_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tOrina_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uLeucocitos uRADType=3
	OpenRow(LANG_FL_tOrina_uLeucocitos,"black");
	printf("<input title='%s' type=text name=uLeucocitos value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uLeucocitos,uLeucocitos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uLeucocitos value='%u' >\n",uLeucocitos);
	}
	//uPiocitos uRADType=3
	OpenRow(LANG_FL_tOrina_uPiocitos,"black");
	printf("<input title='%s' type=text name=uPiocitos value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uPiocitos,uPiocitos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uPiocitos value='%u' >\n",uPiocitos);
	}
	//uHematies uRADType=3
	OpenRow(LANG_FL_tOrina_uHematies,"black");
	printf("<input title='%s' type=text name=uHematies value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uHematies,uHematies);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHematies value='%u' >\n",uHematies);
	}
	//uCelulasEpiteliales uRADType=3
	OpenRow(LANG_FL_tOrina_uCelulasEpiteliales,"black");
	printf("<input title='%s' type=text name=uCelulasEpiteliales value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uCelulasEpiteliales,uCelulasEpiteliales);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCelulasEpiteliales value='%u' >\n",uCelulasEpiteliales);
	}
	//uGermenes uRADType=3
	OpenRow(LANG_FL_tOrina_uGermenes,"black");
	printf("<input title='%s' type=text name=uGermenes value='%u' size=16 maxlength=10 "
		,LANG_FT_tOrina_uGermenes,uGermenes);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uGermenes value='%u' >\n",uGermenes);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tOrina_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tOrina_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tOrina_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tOrina_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tOrina_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tOrinaInput(unsigned uMode)


void tOrina(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttOrinaSelectRow();
		else
			ExttOrinaSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetOrina();
				unxsSalud("New tOrina table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tOrina WHERE uOrina=%u"
						,uOrina);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uOrina);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uLeucocitos);
		sscanf(field[3],"%u",&uPiocitos);
		sscanf(field[4],"%u",&uHematies);
		sscanf(field[5],"%u",&uCelulasEpiteliales);
		sscanf(field[6],"%u",&uGermenes);
		sscanf(field[7],"%u",&uOwner);
		sscanf(field[8],"%u",&uCreatedBy);
		sscanf(field[9],"%lu",&uCreatedDate);
		sscanf(field[10],"%u",&uModBy);
		sscanf(field[11],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Orina",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tOrinaTools>");
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

        ExttOrinaButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tOrina Record Data",100);

	if(guMode==2000 || guMode==2002)
		tOrinaInput(1);
	else
		tOrinaInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttOrinaAuxTable();

	FooterRAD4();

}//end of tOrina();


void NewtOrina(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uOrina FROM tOrina WHERE uOrina=%u",uOrina);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tOrina(LANG_NBR_RECEXISTS);

	Insert_tOrina();
	uOrina=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tOrina",uOrina);
	unxsSaludLog(uOrina,"tOrina","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uOrina);
		tOrina(gcQuery);
	}

}//NewtOrina(unsigned uMode)


void DeletetOrina(void)
{
	sprintf(gcQuery,"DELETE FROM tOrina WHERE uOrina=%u AND ( uOwner=%u OR %u>9 )"
					,uOrina,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uOrina,"tOrina","Del");
		tOrina(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uOrina,"tOrina","DelError");
		tOrina(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetOrina(void)


void Insert_tOrina(void)
{
	sprintf(gcQuery,"INSERT INTO tOrina SET "
		"cLabel='%s',"
		"uLeucocitos=%u,"
		"uPiocitos=%u,"
		"uHematies=%u,"
		"uCelulasEpiteliales=%u,"
		"uGermenes=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uLeucocitos
			,uPiocitos
			,uHematies
			,uCelulasEpiteliales
			,uGermenes
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tOrina(void)


void Update_tOrina(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tOrina SET "
		"cLabel='%s',"
		"uLeucocitos=%u,"
		"uPiocitos=%u,"
		"uHematies=%u,"
		"uCelulasEpiteliales=%u,"
		"uGermenes=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uLeucocitos
			,uPiocitos
			,uHematies
			,uCelulasEpiteliales
			,uGermenes
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tOrina(void)


void ModtOrina(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tOrina.uOrina,"
				" tOrina.uModDate"
				" FROM tOrina,tClient"
				" WHERE tOrina.uOrina=%u"
				" AND tOrina.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uOrina,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uOrina,uModDate FROM tOrina"
				" WHERE uOrina=%u"
					,uOrina);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tOrina(LANG_NBR_RECNOTEXIST);
	if(i>1) tOrina(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tOrina(LANG_NBR_EXTMOD);

	Update_tOrina(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tOrina",uOrina);
	unxsSaludLog(uOrina,"tOrina","Mod");
	tOrina(gcQuery);

}//ModtOrina(void)


void tOrinaList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttOrinaListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tOrinaList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttOrinaListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uOrina"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uLeucocitos"
		"<td><font face=arial,helvetica color=white>uPiocitos"
		"<td><font face=arial,helvetica color=white>uHematies"
		"<td><font face=arial,helvetica color=white>uCelulasEpiteliales"
		"<td><font face=arial,helvetica color=white>uGermenes"
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
				char cBuf7[128];
		sprintf(cBuf7,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[7],
			ForeignKey("tClient","cLabel",strtoul(field[7],NULL,10)));
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
		char cBuf10[128];
		sprintf(cBuf10,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[10],
			ForeignKey("tClient","cLabel",strtoul(field[10],NULL,10)));
		time_t luTime11=strtoul(field[11],NULL,10);
		char cBuf11[32];
		if(luTime11)
			ctime_r(&luTime11,cBuf11);
		else
			sprintf(cBuf11,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tOrina&uOrina=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,field[2]
			,field[3]
			,field[4]
			,field[5]
			,field[6]
			,cBuf7
			,cBuf8
			,cBuf9
			,cBuf10
			,cBuf11
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tOrinaList()


void CreatetOrina(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tOrina ("
		"uOrina INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uLeucocitos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uPiocitos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHematies INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCelulasEpiteliales INT UNSIGNED NOT NULL DEFAULT 0,"
		"uGermenes INT UNSIGNED NOT NULL DEFAULT 0,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetOrina(void)



