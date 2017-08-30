/*
FILE
	tvitales.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tvitalesfunc.h
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
static unsigned uVitales=0;
static char cLabel[33]={""};
static unsigned uPaciente=0;
static char cuPacientePullDown[256]={""};
static unsigned uTemp=0;
static unsigned uTAS=0;
static unsigned uTAD=0;
static unsigned uSatO2=0;
static unsigned uFC=0;
static unsigned uFR=0;
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tVitales "tVitales.uVitales,tVitales.cLabel,tVitales.uPaciente,tVitales.uTemp,tVitales.uTAS,tVitales.uTAD,tVitales.uSatO2,tVitales.uFC,tVitales.uFR,tVitales.uOwner,tVitales.uCreatedBy,tVitales.uCreatedDate,tVitales.uModBy,tVitales.uModDate"

 //Local only
void Insert_tVitales(void);
void Update_tVitales(char *cRowid);
void ProcesstVitalesListVars(pentry entries[], int x);

 //In tVitalesfunc.h file included below
void ExtProcesstVitalesVars(pentry entries[], int x);
void ExttVitalesCommands(pentry entries[], int x);
void ExttVitalesButtons(void);
void ExttVitalesNavBar(void);
void ExttVitalesGetHook(entry gentries[], int x);
void ExttVitalesSelect(void);
void ExttVitalesSelectRow(void);
void ExttVitalesListSelect(void);
void ExttVitalesListFilter(void);
void ExttVitalesAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tvitalesfunc.h"

 //Table Variables Assignment Function
void ProcesstVitalesVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uVitales"))
			sscanf(entries[i].val,"%u",&uVitales);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uPaciente"))
			sscanf(entries[i].val,"%u",&uPaciente);
		else if(!strcmp(entries[i].name,"cuPacientePullDown"))
		{
			sprintf(cuPacientePullDown,"%.255s",entries[i].val);
			uPaciente=ReadPullDown("tPaciente","cLabel",cuPacientePullDown);
		}
		else if(!strcmp(entries[i].name,"uTemp"))
			sscanf(entries[i].val,"%u",&uTemp);
		else if(!strcmp(entries[i].name,"uTAS"))
			sscanf(entries[i].val,"%u",&uTAS);
		else if(!strcmp(entries[i].name,"uTAD"))
			sscanf(entries[i].val,"%u",&uTAD);
		else if(!strcmp(entries[i].name,"uSatO2"))
			sscanf(entries[i].val,"%u",&uSatO2);
		else if(!strcmp(entries[i].name,"uFC"))
			sscanf(entries[i].val,"%u",&uFC);
		else if(!strcmp(entries[i].name,"uFR"))
			sscanf(entries[i].val,"%u",&uFR);
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
	ExtProcesstVitalesVars(entries,x);

}//ProcesstVitalesVars()


void ProcesstVitalesListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstVitalesListVars(pentry entries[], int x)


int tVitalesCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttVitalesCommands(entries,x);

	if(!strcmp(gcFunction,"tVitalesTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tVitalesList();
		}

		//Default
		ProcesstVitalesVars(entries,x);
		tVitales("");
	}
	else if(!strcmp(gcFunction,"tVitalesList"))
	{
		ProcessControlVars(entries,x);
		ProcesstVitalesListVars(entries,x);
		tVitalesList();
	}

	return(0);

}//tVitalesCommands()


void tVitalesInput(unsigned uMode)
{
	
	//uVitales uRADType=1001
	OpenRow(LANG_FL_tVitales_uVitales,"black");
	printf("<input title='%s' type=text name=uVitales value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uVitales,uVitales);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uVitales value='%u' >\n",uVitales);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tVitales_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tVitales_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tVitales_uPaciente,"black");
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
	//uTemp uRADType=3
	OpenRow(LANG_FL_tVitales_uTemp,"black");
	printf("<input title='%s' type=text name=uTemp value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uTemp,uTemp);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTemp value='%u' >\n",uTemp);
	}
	//uTAS uRADType=3
	OpenRow(LANG_FL_tVitales_uTAS,"black");
	printf("<input title='%s' type=text name=uTAS value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uTAS,uTAS);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTAS value='%u' >\n",uTAS);
	}
	//uTAD uRADType=3
	OpenRow(LANG_FL_tVitales_uTAD,"black");
	printf("<input title='%s' type=text name=uTAD value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uTAD,uTAD);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTAD value='%u' >\n",uTAD);
	}
	//uSatO2 uRADType=3
	OpenRow(LANG_FL_tVitales_uSatO2,"black");
	printf("<input title='%s' type=text name=uSatO2 value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uSatO2,uSatO2);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uSatO2 value='%u' >\n",uSatO2);
	}
	//uFC uRADType=3
	OpenRow(LANG_FL_tVitales_uFC,"black");
	printf("<input title='%s' type=text name=uFC value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uFC,uFC);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uFC value='%u' >\n",uFC);
	}
	//uFR uRADType=3
	OpenRow(LANG_FL_tVitales_uFR,"black");
	printf("<input title='%s' type=text name=uFR value='%u' size=16 maxlength=10 "
		,LANG_FT_tVitales_uFR,uFR);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uFR value='%u' >\n",uFR);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVitales_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVitales_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tVitales_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tVitales_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tVitales_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tVitalesInput(unsigned uMode)


void tVitales(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttVitalesSelectRow();
		else
			ExttVitalesSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetVitales();
				unxsSalud("New tVitales table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tVitales WHERE uVitales=%u"
						,uVitales);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uVitales);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uPaciente);
		sscanf(field[3],"%u",&uTemp);
		sscanf(field[4],"%u",&uTAS);
		sscanf(field[5],"%u",&uTAD);
		sscanf(field[6],"%u",&uSatO2);
		sscanf(field[7],"%u",&uFC);
		sscanf(field[8],"%u",&uFR);
		sscanf(field[9],"%u",&uOwner);
		sscanf(field[10],"%u",&uCreatedBy);
		sscanf(field[11],"%lu",&uCreatedDate);
		sscanf(field[12],"%u",&uModBy);
		sscanf(field[13],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de signos vitales",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tVitalesTools>");
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

        ExttVitalesButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tVitales Record Data",100);

	if(guMode==2000 || guMode==2002)
		tVitalesInput(1);
	else
		tVitalesInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttVitalesAuxTable();

	FooterRAD4();

}//end of tVitales();


void NewtVitales(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uVitales FROM tVitales WHERE uVitales=%u",uVitales);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tVitales(LANG_NBR_RECEXISTS);

	Insert_tVitales();
	uVitales=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tVitales",uVitales);
	unxsSaludLog(uVitales,"tVitales","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uVitales);
		tVitales(gcQuery);
	}

}//NewtVitales(unsigned uMode)


void DeletetVitales(void)
{
	sprintf(gcQuery,"DELETE FROM tVitales WHERE uVitales=%u AND ( uOwner=%u OR %u>9 )"
					,uVitales,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uVitales,"tVitales","Del");
		tVitales(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uVitales,"tVitales","DelError");
		tVitales(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetVitales(void)


void Insert_tVitales(void)
{
	sprintf(gcQuery,"INSERT INTO tVitales SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"uTemp=%u,"
		"uTAS=%u,"
		"uTAD=%u,"
		"uSatO2=%u,"
		"uFC=%u,"
		"uFR=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uPaciente
			,uTemp
			,uTAS
			,uTAD
			,uSatO2
			,uFC
			,uFR
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tVitales(void)


void Update_tVitales(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tVitales SET "
		"cLabel='%s',"
		"uPaciente=%u,"
		"uTemp=%u,"
		"uTAS=%u,"
		"uTAD=%u,"
		"uSatO2=%u,"
		"uFC=%u,"
		"uFR=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uPaciente
			,uTemp
			,uTAS
			,uTAD
			,uSatO2
			,uFC
			,uFR
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tVitales(void)


void ModtVitales(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tVitales.uVitales,"
				" tVitales.uModDate"
				" FROM tVitales,tClient"
				" WHERE tVitales.uVitales=%u"
				" AND tVitales.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uVitales,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uVitales,uModDate FROM tVitales"
				" WHERE uVitales=%u"
					,uVitales);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tVitales(LANG_NBR_RECNOTEXIST);
	if(i>1) tVitales(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tVitales(LANG_NBR_EXTMOD);

	Update_tVitales(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tVitales",uVitales);
	unxsSaludLog(uVitales,"tVitales","Mod");
	tVitales(gcQuery);

}//ModtVitales(void)


void tVitalesList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttVitalesListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tVitalesList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttVitalesListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uVitales"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uPaciente"
		"<td><font face=arial,helvetica color=white>uTemp"
		"<td><font face=arial,helvetica color=white>uTAS"
		"<td><font face=arial,helvetica color=white>uTAD"
		"<td><font face=arial,helvetica color=white>uSatO2"
		"<td><font face=arial,helvetica color=white>uFC"
		"<td><font face=arial,helvetica color=white>uFR"
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
		char cBuf9[128];
		sprintf(cBuf9,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[9],
			ForeignKey("tClient","cLabel",strtoul(field[9],NULL,10)));
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
		char cBuf12[128];
		sprintf(cBuf12,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[12],
			ForeignKey("tClient","cLabel",strtoul(field[12],NULL,10)));
		time_t luTime13=strtoul(field[13],NULL,10);
		char cBuf13[32];
		if(luTime13)
			ctime_r(&luTime13,cBuf13);
		else
			sprintf(cBuf13,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tVitales&uVitales=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,cBuf2
			,field[3]
			,field[4]
			,field[5]
			,field[6]
			,field[7]
			,field[8]
			,cBuf9
			,cBuf10
			,cBuf11
			,cBuf12
			,cBuf13
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tVitalesList()


void CreatetVitales(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tVitales ("
		"uVitales INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uPaciente INT UNSIGNED ,"
		"uTemp INT UNSIGNED NOT NULL DEFAULT 0,"
		"uTAS INT UNSIGNED NOT NULL DEFAULT 0,"
		"uTAD INT UNSIGNED NOT NULL DEFAULT 0,"
		"uSatO2 INT UNSIGNED NOT NULL DEFAULT 0,"
		"uFC INT UNSIGNED NOT NULL DEFAULT 0,"
		"uFR INT UNSIGNED NOT NULL DEFAULT 0,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetVitales(void)



