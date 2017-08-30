/*
FILE
	tmicrobiologia.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tmicrobiologiafunc.h
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
static unsigned uMicrobiologia=0;
static char cLabel[33]={""};
static unsigned uHemocultivo=0;
static char cuHemocultivoPullDown[256]={""};
static unsigned uUrocultivo=0;
static char cuUrocultivoPullDown[256]={""};
static unsigned uCultivoEsputo=0;
static char cuCultivoEsputoPullDown[256]={""};
static unsigned uCultivoPB=0;
static char cuCultivoPBPullDown[256]={""};
static unsigned uCultivoHueso=0;
static char cuCultivoHuesoPullDown[256]={""};
static unsigned uCultivoCateter=0;
static char cuCultivoCateterPullDown[256]={""};
static unsigned uCultivoLCR=0;
static char cuCultivoLCRPullDown[256]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tMicrobiologia "tMicrobiologia.uMicrobiologia,tMicrobiologia.cLabel,tMicrobiologia.uHemocultivo,tMicrobiologia.uUrocultivo,tMicrobiologia.uCultivoEsputo,tMicrobiologia.uCultivoPB,tMicrobiologia.uCultivoHueso,tMicrobiologia.uCultivoCateter,tMicrobiologia.uCultivoLCR,tMicrobiologia.uOwner,tMicrobiologia.uCreatedBy,tMicrobiologia.uCreatedDate,tMicrobiologia.uModBy,tMicrobiologia.uModDate"

 //Local only
void Insert_tMicrobiologia(void);
void Update_tMicrobiologia(char *cRowid);
void ProcesstMicrobiologiaListVars(pentry entries[], int x);

 //In tMicrobiologiafunc.h file included below
void ExtProcesstMicrobiologiaVars(pentry entries[], int x);
void ExttMicrobiologiaCommands(pentry entries[], int x);
void ExttMicrobiologiaButtons(void);
void ExttMicrobiologiaNavBar(void);
void ExttMicrobiologiaGetHook(entry gentries[], int x);
void ExttMicrobiologiaSelect(void);
void ExttMicrobiologiaSelectRow(void);
void ExttMicrobiologiaListSelect(void);
void ExttMicrobiologiaListFilter(void);
void ExttMicrobiologiaAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tmicrobiologiafunc.h"

 //Table Variables Assignment Function
void ProcesstMicrobiologiaVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uMicrobiologia"))
			sscanf(entries[i].val,"%u",&uMicrobiologia);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"uHemocultivo"))
			sscanf(entries[i].val,"%u",&uHemocultivo);
		else if(!strcmp(entries[i].name,"cuHemocultivoPullDown"))
		{
			sprintf(cuHemocultivoPullDown,"%.255s",entries[i].val);
			uHemocultivo=ReadPullDown("tHemocultivo","cLabel",cuHemocultivoPullDown);
		}
		else if(!strcmp(entries[i].name,"uUrocultivo"))
			sscanf(entries[i].val,"%u",&uUrocultivo);
		else if(!strcmp(entries[i].name,"cuUrocultivoPullDown"))
		{
			sprintf(cuUrocultivoPullDown,"%.255s",entries[i].val);
			uUrocultivo=ReadPullDown("tUrocultivo","cLabel",cuUrocultivoPullDown);
		}
		else if(!strcmp(entries[i].name,"uCultivoEsputo"))
			sscanf(entries[i].val,"%u",&uCultivoEsputo);
		else if(!strcmp(entries[i].name,"cuCultivoEsputoPullDown"))
		{
			sprintf(cuCultivoEsputoPullDown,"%.255s",entries[i].val);
			uCultivoEsputo=ReadPullDown("tCultivoEsputo","cLabel",cuCultivoEsputoPullDown);
		}
		else if(!strcmp(entries[i].name,"uCultivoPB"))
			sscanf(entries[i].val,"%u",&uCultivoPB);
		else if(!strcmp(entries[i].name,"cuCultivoPBPullDown"))
		{
			sprintf(cuCultivoPBPullDown,"%.255s",entries[i].val);
			uCultivoPB=ReadPullDown("tCultivoPB","cLabel",cuCultivoPBPullDown);
		}
		else if(!strcmp(entries[i].name,"uCultivoHueso"))
			sscanf(entries[i].val,"%u",&uCultivoHueso);
		else if(!strcmp(entries[i].name,"cuCultivoHuesoPullDown"))
		{
			sprintf(cuCultivoHuesoPullDown,"%.255s",entries[i].val);
			uCultivoHueso=ReadPullDown("tCultivoHueso","cLabel",cuCultivoHuesoPullDown);
		}
		else if(!strcmp(entries[i].name,"uCultivoCateter"))
			sscanf(entries[i].val,"%u",&uCultivoCateter);
		else if(!strcmp(entries[i].name,"cuCultivoCateterPullDown"))
		{
			sprintf(cuCultivoCateterPullDown,"%.255s",entries[i].val);
			uCultivoCateter=ReadPullDown("tCultivoCateter","cLabel",cuCultivoCateterPullDown);
		}
		else if(!strcmp(entries[i].name,"uCultivoLCR"))
			sscanf(entries[i].val,"%u",&uCultivoLCR);
		else if(!strcmp(entries[i].name,"cuCultivoLCRPullDown"))
		{
			sprintf(cuCultivoLCRPullDown,"%.255s",entries[i].val);
			uCultivoLCR=ReadPullDown("tCultivoLCR","cLabel",cuCultivoLCRPullDown);
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
	ExtProcesstMicrobiologiaVars(entries,x);

}//ProcesstMicrobiologiaVars()


void ProcesstMicrobiologiaListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstMicrobiologiaListVars(pentry entries[], int x)


int tMicrobiologiaCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttMicrobiologiaCommands(entries,x);

	if(!strcmp(gcFunction,"tMicrobiologiaTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tMicrobiologiaList();
		}

		//Default
		ProcesstMicrobiologiaVars(entries,x);
		tMicrobiologia("");
	}
	else if(!strcmp(gcFunction,"tMicrobiologiaList"))
	{
		ProcessControlVars(entries,x);
		ProcesstMicrobiologiaListVars(entries,x);
		tMicrobiologiaList();
	}

	return(0);

}//tMicrobiologiaCommands()


void tMicrobiologiaInput(unsigned uMode)
{
	
	//uMicrobiologia uRADType=1001
	OpenRow(LANG_FL_tMicrobiologia_uMicrobiologia,"black");
	printf("<input title='%s' type=text name=uMicrobiologia value='%u' size=16 maxlength=10 "
		,LANG_FT_tMicrobiologia_uMicrobiologia,uMicrobiologia);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uMicrobiologia value='%u' >\n",uMicrobiologia);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tMicrobiologia_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tMicrobiologia_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//uHemocultivo COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uHemocultivo,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tHemocultivo;cuHemocultivoPullDown","cLabel","cLabel",uHemocultivo,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tHemocultivo;cuHemocultivoPullDown","cLabel","cLabel",uHemocultivo,0);
	else if(uMode)
		tTablePullDown("tHemocultivo;cuHemocultivoPullDown","cLabel","cLabel",uHemocultivo,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tHemocultivo","cLabel",uHemocultivo));
		printf("<input type=hidden size=20 maxlength=20 name=uHemocultivo value='%u' >\n",uHemocultivo);
	}
	//uUrocultivo COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uUrocultivo,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tUrocultivo;cuUrocultivoPullDown","cLabel","cLabel",uUrocultivo,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tUrocultivo;cuUrocultivoPullDown","cLabel","cLabel",uUrocultivo,0);
	else if(uMode)
		tTablePullDown("tUrocultivo;cuUrocultivoPullDown","cLabel","cLabel",uUrocultivo,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tUrocultivo","cLabel",uUrocultivo));
		printf("<input type=hidden size=20 maxlength=20 name=uUrocultivo value='%u' >\n",uUrocultivo);
	}
	//uCultivoEsputo COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uCultivoEsputo,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tCultivoEsputo;cuCultivoEsputoPullDown","cLabel","cLabel",uCultivoEsputo,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tCultivoEsputo;cuCultivoEsputoPullDown","cLabel","cLabel",uCultivoEsputo,0);
	else if(uMode)
		tTablePullDown("tCultivoEsputo;cuCultivoEsputoPullDown","cLabel","cLabel",uCultivoEsputo,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tCultivoEsputo","cLabel",uCultivoEsputo));
		printf("<input type=hidden size=20 maxlength=20 name=uCultivoEsputo value='%u' >\n",uCultivoEsputo);
	}
	//uCultivoPB COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uCultivoPB,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tCultivoPB;cuCultivoPBPullDown","cLabel","cLabel",uCultivoPB,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tCultivoPB;cuCultivoPBPullDown","cLabel","cLabel",uCultivoPB,0);
	else if(uMode)
		tTablePullDown("tCultivoPB;cuCultivoPBPullDown","cLabel","cLabel",uCultivoPB,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tCultivoPB","cLabel",uCultivoPB));
		printf("<input type=hidden size=20 maxlength=20 name=uCultivoPB value='%u' >\n",uCultivoPB);
	}
	//uCultivoHueso COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uCultivoHueso,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tCultivoHueso;cuCultivoHuesoPullDown","cLabel","cLabel",uCultivoHueso,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tCultivoHueso;cuCultivoHuesoPullDown","cLabel","cLabel",uCultivoHueso,0);
	else if(uMode)
		tTablePullDown("tCultivoHueso;cuCultivoHuesoPullDown","cLabel","cLabel",uCultivoHueso,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tCultivoHueso","cLabel",uCultivoHueso));
		printf("<input type=hidden size=20 maxlength=20 name=uCultivoHueso value='%u' >\n",uCultivoHueso);
	}
	//uCultivoCateter COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uCultivoCateter,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tCultivoCateter;cuCultivoCateterPullDown","cLabel","cLabel",uCultivoCateter,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tCultivoCateter;cuCultivoCateterPullDown","cLabel","cLabel",uCultivoCateter,0);
	else if(uMode)
		tTablePullDown("tCultivoCateter;cuCultivoCateterPullDown","cLabel","cLabel",uCultivoCateter,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tCultivoCateter","cLabel",uCultivoCateter));
		printf("<input type=hidden size=20 maxlength=20 name=uCultivoCateter value='%u' >\n",uCultivoCateter);
	}
	//uCultivoLCR COLTYPE_SELECTTABLE_OWNER
	OpenRow(LANG_FL_tMicrobiologia_uCultivoLCR,"black");
	if(guPermLevel>=0 && guPermLevel<10 && uMode)
		tTablePullDownOwner("tCultivoLCR;cuCultivoLCRPullDown","cLabel","cLabel",uCultivoLCR,1);
	else if(guPermLevel<10 && !uMode)
		tTablePullDownOwner("tCultivoLCR;cuCultivoLCRPullDown","cLabel","cLabel",uCultivoLCR,0);
	else if(uMode)
		tTablePullDown("tCultivoLCR;cuCultivoLCRPullDown","cLabel","cLabel",uCultivoLCR,1);
	else if(1)
	{
		printf("<input type=text size=20 value='%s' disabled>\n",ForeignKey("tCultivoLCR","cLabel",uCultivoLCR));
		printf("<input type=hidden size=20 maxlength=20 name=uCultivoLCR value='%u' >\n",uCultivoLCR);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMicrobiologia_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMicrobiologia_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMicrobiologia_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMicrobiologia_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMicrobiologia_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tMicrobiologiaInput(unsigned uMode)


void tMicrobiologia(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttMicrobiologiaSelectRow();
		else
			ExttMicrobiologiaSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetMicrobiologia();
				unxsSalud("New tMicrobiologia table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tMicrobiologia WHERE uMicrobiologia=%u"
						,uMicrobiologia);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uMicrobiologia);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uHemocultivo);
		sscanf(field[3],"%u",&uUrocultivo);
		sscanf(field[4],"%u",&uCultivoEsputo);
		sscanf(field[5],"%u",&uCultivoPB);
		sscanf(field[6],"%u",&uCultivoHueso);
		sscanf(field[7],"%u",&uCultivoCateter);
		sscanf(field[8],"%u",&uCultivoLCR);
		sscanf(field[9],"%u",&uOwner);
		sscanf(field[10],"%u",&uCreatedBy);
		sscanf(field[11],"%lu",&uCreatedDate);
		sscanf(field[12],"%u",&uModBy);
		sscanf(field[13],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Microbiologia",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tMicrobiologiaTools>");
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

        ExttMicrobiologiaButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tMicrobiologia Record Data",100);

	if(guMode==2000 || guMode==2002)
		tMicrobiologiaInput(1);
	else
		tMicrobiologiaInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttMicrobiologiaAuxTable();

	FooterRAD4();

}//end of tMicrobiologia();


void NewtMicrobiologia(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uMicrobiologia FROM tMicrobiologia WHERE uMicrobiologia=%u",uMicrobiologia);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tMicrobiologia(LANG_NBR_RECEXISTS);

	Insert_tMicrobiologia();
	uMicrobiologia=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tMicrobiologia",uMicrobiologia);
	unxsSaludLog(uMicrobiologia,"tMicrobiologia","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uMicrobiologia);
		tMicrobiologia(gcQuery);
	}

}//NewtMicrobiologia(unsigned uMode)


void DeletetMicrobiologia(void)
{
	sprintf(gcQuery,"DELETE FROM tMicrobiologia WHERE uMicrobiologia=%u AND ( uOwner=%u OR %u>9 )"
					,uMicrobiologia,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uMicrobiologia,"tMicrobiologia","Del");
		tMicrobiologia(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uMicrobiologia,"tMicrobiologia","DelError");
		tMicrobiologia(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetMicrobiologia(void)


void Insert_tMicrobiologia(void)
{
	sprintf(gcQuery,"INSERT INTO tMicrobiologia SET "
		"cLabel='%s',"
		"uHemocultivo=%u,"
		"uUrocultivo=%u,"
		"uCultivoEsputo=%u,"
		"uCultivoPB=%u,"
		"uCultivoHueso=%u,"
		"uCultivoCateter=%u,"
		"uCultivoLCR=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uHemocultivo
			,uUrocultivo
			,uCultivoEsputo
			,uCultivoPB
			,uCultivoHueso
			,uCultivoCateter
			,uCultivoLCR
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tMicrobiologia(void)


void Update_tMicrobiologia(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tMicrobiologia SET "
		"cLabel='%s',"
		"uHemocultivo=%u,"
		"uUrocultivo=%u,"
		"uCultivoEsputo=%u,"
		"uCultivoPB=%u,"
		"uCultivoHueso=%u,"
		"uCultivoCateter=%u,"
		"uCultivoLCR=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,uHemocultivo
			,uUrocultivo
			,uCultivoEsputo
			,uCultivoPB
			,uCultivoHueso
			,uCultivoCateter
			,uCultivoLCR
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tMicrobiologia(void)


void ModtMicrobiologia(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tMicrobiologia.uMicrobiologia,"
				" tMicrobiologia.uModDate"
				" FROM tMicrobiologia,tClient"
				" WHERE tMicrobiologia.uMicrobiologia=%u"
				" AND tMicrobiologia.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uMicrobiologia,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uMicrobiologia,uModDate FROM tMicrobiologia"
				" WHERE uMicrobiologia=%u"
					,uMicrobiologia);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tMicrobiologia(LANG_NBR_RECNOTEXIST);
	if(i>1) tMicrobiologia(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tMicrobiologia(LANG_NBR_EXTMOD);

	Update_tMicrobiologia(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tMicrobiologia",uMicrobiologia);
	unxsSaludLog(uMicrobiologia,"tMicrobiologia","Mod");
	tMicrobiologia(gcQuery);

}//ModtMicrobiologia(void)


void tMicrobiologiaList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttMicrobiologiaListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tMicrobiologiaList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttMicrobiologiaListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uMicrobiologia"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>uHemocultivo"
		"<td><font face=arial,helvetica color=white>uUrocultivo"
		"<td><font face=arial,helvetica color=white>uCultivoEsputo"
		"<td><font face=arial,helvetica color=white>uCultivoPB"
		"<td><font face=arial,helvetica color=white>uCultivoHueso"
		"<td><font face=arial,helvetica color=white>uCultivoCateter"
		"<td><font face=arial,helvetica color=white>uCultivoLCR"
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
		sprintf(cBuf2,"<a class=darkLink href=?gcFunction=tHemocultivo&uHemocultivo=%.32s>%.32s</a>",
			field[2],
			ForeignKey("tHemocultivo","cLabel",strtoul(field[2],NULL,10)));
		char cBuf3[128];
		sprintf(cBuf3,"<a class=darkLink href=?gcFunction=tUrocultivo&uUrocultivo=%.32s>%.32s</a>",
			field[3],
			ForeignKey("tUrocultivo","cLabel",strtoul(field[3],NULL,10)));
		char cBuf4[128];
		sprintf(cBuf4,"<a class=darkLink href=?gcFunction=tCultivoEsputo&uCultivoEsputo=%.32s>%.32s</a>",
			field[4],
			ForeignKey("tCultivoEsputo","cLabel",strtoul(field[4],NULL,10)));
		char cBuf5[128];
		sprintf(cBuf5,"<a class=darkLink href=?gcFunction=tCultivoPB&uCultivoPB=%.32s>%.32s</a>",
			field[5],
			ForeignKey("tCultivoPB","cLabel",strtoul(field[5],NULL,10)));
		char cBuf6[128];
		sprintf(cBuf6,"<a class=darkLink href=?gcFunction=tCultivoHueso&uCultivoHueso=%.32s>%.32s</a>",
			field[6],
			ForeignKey("tCultivoHueso","cLabel",strtoul(field[6],NULL,10)));
		char cBuf7[128];
		sprintf(cBuf7,"<a class=darkLink href=?gcFunction=tCultivoCateter&uCultivoCateter=%.32s>%.32s</a>",
			field[7],
			ForeignKey("tCultivoCateter","cLabel",strtoul(field[7],NULL,10)));
		char cBuf8[128];
		sprintf(cBuf8,"<a class=darkLink href=?gcFunction=tCultivoLCR&uCultivoLCR=%.32s>%.32s</a>",
			field[8],
			ForeignKey("tCultivoLCR","cLabel",strtoul(field[8],NULL,10)));
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tMicrobiologia&uMicrobiologia=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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
			,cBuf10
			,cBuf11
			,cBuf12
			,cBuf13
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tMicrobiologiaList()


void CreatetMicrobiologia(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tMicrobiologia ("
		"uMicrobiologia INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uHemocultivo INT UNSIGNED ,"
		"uUrocultivo INT UNSIGNED ,"
		"uCultivoEsputo INT UNSIGNED ,"
		"uCultivoPB INT UNSIGNED ,"
		"uCultivoHueso INT UNSIGNED ,"
		"uCultivoCateter INT UNSIGNED ,"
		"uCultivoLCR INT UNSIGNED ,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetMicrobiologia(void)



