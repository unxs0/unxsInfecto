/*
FILE
	tserologia.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tserologiafunc.h
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
static unsigned uSerologia=0;
static char cLabel[33]={""};
static char *cNotas={""};
static unsigned uHVAIgM=0;
static unsigned uHVAIgG=0;
static unsigned uHBVsAg=0;
static unsigned uHVBanticoreIgM=0;
static unsigned uHVBanticoreIgG=0;
static unsigned uHVC=0;
static unsigned uCMVIgM=0;
static unsigned uToxoIgM=0;
static unsigned uToxoIgG=0;
static unsigned uChagas=0;
static unsigned uHIV=0;
static unsigned uCVHIV=0;
static unsigned uCVHVC=0;
static unsigned uCVHVB=0;
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tSerologia "tSerologia.uSerologia,tSerologia.cLabel,tSerologia.cNotas,tSerologia.uHVAIgM,tSerologia.uHVAIgG,tSerologia.uHBVsAg,tSerologia.uHVBanticoreIgM,tSerologia.uHVBanticoreIgG,tSerologia.uHVC,tSerologia.uCMVIgM,tSerologia.uToxoIgM,tSerologia.uToxoIgG,tSerologia.uChagas,tSerologia.uHIV,tSerologia.uCVHIV,tSerologia.uCVHVC,tSerologia.uCVHVB,tSerologia.uOwner,tSerologia.uCreatedBy,tSerologia.uCreatedDate,tSerologia.uModBy,tSerologia.uModDate"

 //Local only
void Insert_tSerologia(void);
void Update_tSerologia(char *cRowid);
void ProcesstSerologiaListVars(pentry entries[], int x);

 //In tSerologiafunc.h file included below
void ExtProcesstSerologiaVars(pentry entries[], int x);
void ExttSerologiaCommands(pentry entries[], int x);
void ExttSerologiaButtons(void);
void ExttSerologiaNavBar(void);
void ExttSerologiaGetHook(entry gentries[], int x);
void ExttSerologiaSelect(void);
void ExttSerologiaSelectRow(void);
void ExttSerologiaListSelect(void);
void ExttSerologiaListFilter(void);
void ExttSerologiaAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tserologiafunc.h"

 //Table Variables Assignment Function
void ProcesstSerologiaVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uSerologia"))
			sscanf(entries[i].val,"%u",&uSerologia);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"cNotas"))
			cNotas=entries[i].val;
		else if(!strcmp(entries[i].name,"uHVAIgM"))
			sscanf(entries[i].val,"%u",&uHVAIgM);
		else if(!strcmp(entries[i].name,"uHVAIgG"))
			sscanf(entries[i].val,"%u",&uHVAIgG);
		else if(!strcmp(entries[i].name,"uHBVsAg"))
			sscanf(entries[i].val,"%u",&uHBVsAg);
		else if(!strcmp(entries[i].name,"uHVBanticoreIgM"))
			sscanf(entries[i].val,"%u",&uHVBanticoreIgM);
		else if(!strcmp(entries[i].name,"uHVBanticoreIgG"))
			sscanf(entries[i].val,"%u",&uHVBanticoreIgG);
		else if(!strcmp(entries[i].name,"uHVC"))
			sscanf(entries[i].val,"%u",&uHVC);
		else if(!strcmp(entries[i].name,"uCMVIgM"))
			sscanf(entries[i].val,"%u",&uCMVIgM);
		else if(!strcmp(entries[i].name,"uToxoIgM"))
			sscanf(entries[i].val,"%u",&uToxoIgM);
		else if(!strcmp(entries[i].name,"uToxoIgG"))
			sscanf(entries[i].val,"%u",&uToxoIgG);
		else if(!strcmp(entries[i].name,"uChagas"))
			sscanf(entries[i].val,"%u",&uChagas);
		else if(!strcmp(entries[i].name,"uHIV"))
			sscanf(entries[i].val,"%u",&uHIV);
		else if(!strcmp(entries[i].name,"uCVHIV"))
			sscanf(entries[i].val,"%u",&uCVHIV);
		else if(!strcmp(entries[i].name,"uCVHVC"))
			sscanf(entries[i].val,"%u",&uCVHVC);
		else if(!strcmp(entries[i].name,"uCVHVB"))
			sscanf(entries[i].val,"%u",&uCVHVB);
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
	ExtProcesstSerologiaVars(entries,x);

}//ProcesstSerologiaVars()


void ProcesstSerologiaListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstSerologiaListVars(pentry entries[], int x)


int tSerologiaCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttSerologiaCommands(entries,x);

	if(!strcmp(gcFunction,"tSerologiaTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tSerologiaList();
		}

		//Default
		ProcesstSerologiaVars(entries,x);
		tSerologia("");
	}
	else if(!strcmp(gcFunction,"tSerologiaList"))
	{
		ProcessControlVars(entries,x);
		ProcesstSerologiaListVars(entries,x);
		tSerologiaList();
	}

	return(0);

}//tSerologiaCommands()


void tSerologiaInput(unsigned uMode)
{
	
	//uSerologia uRADType=1001
	OpenRow(LANG_FL_tSerologia_uSerologia,"black");
	printf("<input title='%s' type=text name=uSerologia value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uSerologia,uSerologia);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uSerologia value='%u' >\n",uSerologia);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tSerologia_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tSerologia_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//cNotas COLTYPE_TEXT
	OpenRow(LANG_FL_tSerologia_cNotas,"black");
	printf("<textarea title='%s' cols=80 wrap=hard rows=16 name=cNotas "
,LANG_FT_tSerologia_cNotas);
	if(guPermLevel>=0 && uMode)
	{
		printf(">%s</textarea></td></tr>\n",cNotas);
	}
	else
	{
		printf("disabled>%s</textarea></td></tr>\n",cNotas);
		printf("<input type=hidden name=cNotas value=\"%s\" >\n",EncodeDoubleQuotes(cNotas));
	}
	//uHVAIgM uRADType=3
	OpenRow(LANG_FL_tSerologia_uHVAIgM,"black");
	printf("<input title='%s' type=text name=uHVAIgM value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHVAIgM,uHVAIgM);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVAIgM value='%u' >\n",uHVAIgM);
	}
	//uHVAIgG uRADType=3
	OpenRow(LANG_FL_tSerologia_uHVAIgG,"black");
	printf("<input title='%s' type=text name=uHVAIgG value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHVAIgG,uHVAIgG);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVAIgG value='%u' >\n",uHVAIgG);
	}
	//uHBVsAg uRADType=3
	OpenRow(LANG_FL_tSerologia_uHBVsAg,"black");
	printf("<input title='%s' type=text name=uHBVsAg value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHBVsAg,uHBVsAg);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHBVsAg value='%u' >\n",uHBVsAg);
	}
	//uHVBanticoreIgM uRADType=3
	OpenRow(LANG_FL_tSerologia_uHVBanticoreIgM,"black");
	printf("<input title='%s' type=text name=uHVBanticoreIgM value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHVBanticoreIgM,uHVBanticoreIgM);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVBanticoreIgM value='%u' >\n",uHVBanticoreIgM);
	}
	//uHVBanticoreIgG uRADType=3
	OpenRow(LANG_FL_tSerologia_uHVBanticoreIgG,"black");
	printf("<input title='%s' type=text name=uHVBanticoreIgG value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHVBanticoreIgG,uHVBanticoreIgG);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVBanticoreIgG value='%u' >\n",uHVBanticoreIgG);
	}
	//uHVC uRADType=3
	OpenRow(LANG_FL_tSerologia_uHVC,"black");
	printf("<input title='%s' type=text name=uHVC value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHVC,uHVC);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHVC value='%u' >\n",uHVC);
	}
	//uCMVIgM uRADType=3
	OpenRow(LANG_FL_tSerologia_uCMVIgM,"black");
	printf("<input title='%s' type=text name=uCMVIgM value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uCMVIgM,uCMVIgM);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCMVIgM value='%u' >\n",uCMVIgM);
	}
	//uToxoIgM uRADType=3
	OpenRow(LANG_FL_tSerologia_uToxoIgM,"black");
	printf("<input title='%s' type=text name=uToxoIgM value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uToxoIgM,uToxoIgM);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uToxoIgM value='%u' >\n",uToxoIgM);
	}
	//uToxoIgG uRADType=3
	OpenRow(LANG_FL_tSerologia_uToxoIgG,"black");
	printf("<input title='%s' type=text name=uToxoIgG value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uToxoIgG,uToxoIgG);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uToxoIgG value='%u' >\n",uToxoIgG);
	}
	//uChagas uRADType=3
	OpenRow(LANG_FL_tSerologia_uChagas,"black");
	printf("<input title='%s' type=text name=uChagas value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uChagas,uChagas);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uChagas value='%u' >\n",uChagas);
	}
	//uHIV uRADType=3
	OpenRow(LANG_FL_tSerologia_uHIV,"black");
	printf("<input title='%s' type=text name=uHIV value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uHIV,uHIV);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHIV value='%u' >\n",uHIV);
	}
	//uCVHIV uRADType=3
	OpenRow(LANG_FL_tSerologia_uCVHIV,"black");
	printf("<input title='%s' type=text name=uCVHIV value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uCVHIV,uCVHIV);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCVHIV value='%u' >\n",uCVHIV);
	}
	//uCVHVC uRADType=3
	OpenRow(LANG_FL_tSerologia_uCVHVC,"black");
	printf("<input title='%s' type=text name=uCVHVC value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uCVHVC,uCVHVC);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCVHVC value='%u' >\n",uCVHVC);
	}
	//uCVHVB uRADType=3
	OpenRow(LANG_FL_tSerologia_uCVHVB,"black");
	printf("<input title='%s' type=text name=uCVHVB value='%u' size=16 maxlength=10 "
		,LANG_FT_tSerologia_uCVHVB,uCVHVB);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCVHVB value='%u' >\n",uCVHVB);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSerologia_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSerologia_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tSerologia_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSerologia_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tSerologia_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tSerologiaInput(unsigned uMode)


void tSerologia(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttSerologiaSelectRow();
		else
			ExttSerologiaSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetSerologia();
				unxsSalud("New tSerologia table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tSerologia WHERE uSerologia=%u"
						,uSerologia);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uSerologia);
		sprintf(cLabel,"%.32s",field[1]);
		cNotas=field[2];
		sscanf(field[3],"%u",&uHVAIgM);
		sscanf(field[4],"%u",&uHVAIgG);
		sscanf(field[5],"%u",&uHBVsAg);
		sscanf(field[6],"%u",&uHVBanticoreIgM);
		sscanf(field[7],"%u",&uHVBanticoreIgG);
		sscanf(field[8],"%u",&uHVC);
		sscanf(field[9],"%u",&uCMVIgM);
		sscanf(field[10],"%u",&uToxoIgM);
		sscanf(field[11],"%u",&uToxoIgG);
		sscanf(field[12],"%u",&uChagas);
		sscanf(field[13],"%u",&uHIV);
		sscanf(field[14],"%u",&uCVHIV);
		sscanf(field[15],"%u",&uCVHVC);
		sscanf(field[16],"%u",&uCVHVB);
		sscanf(field[17],"%u",&uOwner);
		sscanf(field[18],"%u",&uCreatedBy);
		sscanf(field[19],"%lu",&uCreatedDate);
		sscanf(field[20],"%u",&uModBy);
		sscanf(field[21],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Serologia",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tSerologiaTools>");
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

        ExttSerologiaButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tSerologia Record Data",100);

	if(guMode==2000 || guMode==2002)
		tSerologiaInput(1);
	else
		tSerologiaInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttSerologiaAuxTable();

	FooterRAD4();

}//end of tSerologia();


void NewtSerologia(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uSerologia FROM tSerologia WHERE uSerologia=%u",uSerologia);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tSerologia(LANG_NBR_RECEXISTS);

	Insert_tSerologia();
	uSerologia=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tSerologia",uSerologia);
	unxsSaludLog(uSerologia,"tSerologia","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uSerologia);
		tSerologia(gcQuery);
	}

}//NewtSerologia(unsigned uMode)


void DeletetSerologia(void)
{
	sprintf(gcQuery,"DELETE FROM tSerologia WHERE uSerologia=%u AND ( uOwner=%u OR %u>9 )"
					,uSerologia,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uSerologia,"tSerologia","Del");
		tSerologia(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uSerologia,"tSerologia","DelError");
		tSerologia(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetSerologia(void)


void Insert_tSerologia(void)
{
	sprintf(gcQuery,"INSERT INTO tSerologia SET "
		"cLabel='%s',"
		"cNotas='%s',"
		"uHVAIgM=%u,"
		"uHVAIgG=%u,"
		"uHBVsAg=%u,"
		"uHVBanticoreIgM=%u,"
		"uHVBanticoreIgG=%u,"
		"uHVC=%u,"
		"uCMVIgM=%u,"
		"uToxoIgM=%u,"
		"uToxoIgG=%u,"
		"uChagas=%u,"
		"uHIV=%u,"
		"uCVHIV=%u,"
		"uCVHVC=%u,"
		"uCVHVB=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,TextAreaSave(cNotas)
			,uHVAIgM
			,uHVAIgG
			,uHBVsAg
			,uHVBanticoreIgM
			,uHVBanticoreIgG
			,uHVC
			,uCMVIgM
			,uToxoIgM
			,uToxoIgG
			,uChagas
			,uHIV
			,uCVHIV
			,uCVHVC
			,uCVHVB
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tSerologia(void)


void Update_tSerologia(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tSerologia SET "
		"cLabel='%s',"
		"cNotas='%s',"
		"uHVAIgM=%u,"
		"uHVAIgG=%u,"
		"uHBVsAg=%u,"
		"uHVBanticoreIgM=%u,"
		"uHVBanticoreIgG=%u,"
		"uHVC=%u,"
		"uCMVIgM=%u,"
		"uToxoIgM=%u,"
		"uToxoIgG=%u,"
		"uChagas=%u,"
		"uHIV=%u,"
		"uCVHIV=%u,"
		"uCVHVC=%u,"
		"uCVHVB=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,TextAreaSave(cNotas)
			,uHVAIgM
			,uHVAIgG
			,uHBVsAg
			,uHVBanticoreIgM
			,uHVBanticoreIgG
			,uHVC
			,uCMVIgM
			,uToxoIgM
			,uToxoIgG
			,uChagas
			,uHIV
			,uCVHIV
			,uCVHVC
			,uCVHVB
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tSerologia(void)


void ModtSerologia(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tSerologia.uSerologia,"
				" tSerologia.uModDate"
				" FROM tSerologia,tClient"
				" WHERE tSerologia.uSerologia=%u"
				" AND tSerologia.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uSerologia,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uSerologia,uModDate FROM tSerologia"
				" WHERE uSerologia=%u"
					,uSerologia);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tSerologia(LANG_NBR_RECNOTEXIST);
	if(i>1) tSerologia(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tSerologia(LANG_NBR_EXTMOD);

	Update_tSerologia(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tSerologia",uSerologia);
	unxsSaludLog(uSerologia,"tSerologia","Mod");
	tSerologia(gcQuery);

}//ModtSerologia(void)


void tSerologiaList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttSerologiaListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tSerologiaList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttSerologiaListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uSerologia"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>cNotas"
		"<td><font face=arial,helvetica color=white>uHVAIgM"
		"<td><font face=arial,helvetica color=white>uHVAIgG"
		"<td><font face=arial,helvetica color=white>uHBVsAg"
		"<td><font face=arial,helvetica color=white>uHVBanticoreIgM"
		"<td><font face=arial,helvetica color=white>uHVBanticoreIgG"
		"<td><font face=arial,helvetica color=white>uHVC"
		"<td><font face=arial,helvetica color=white>uCMVIgM"
		"<td><font face=arial,helvetica color=white>uToxoIgM"
		"<td><font face=arial,helvetica color=white>uToxoIgG"
		"<td><font face=arial,helvetica color=white>uChagas"
		"<td><font face=arial,helvetica color=white>uHIV"
		"<td><font face=arial,helvetica color=white>uCVHIV"
		"<td><font face=arial,helvetica color=white>uCVHVC"
		"<td><font face=arial,helvetica color=white>uCVHVB"
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
				char cBuf17[128];
		sprintf(cBuf17,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[17],
			ForeignKey("tClient","cLabel",strtoul(field[17],NULL,10)));
		char cBuf18[128];
		sprintf(cBuf18,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[18],
			ForeignKey("tClient","cLabel",strtoul(field[18],NULL,10)));
		time_t luTime19=strtoul(field[19],NULL,10);
		char cBuf19[32];
		if(luTime19)
			ctime_r(&luTime19,cBuf19);
		else
			sprintf(cBuf19,"---");
		char cBuf20[128];
		sprintf(cBuf20,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[20],
			ForeignKey("tClient","cLabel",strtoul(field[20],NULL,10)));
		time_t luTime21=strtoul(field[21],NULL,10);
		char cBuf21[32];
		if(luTime21)
			ctime_r(&luTime21,cBuf21);
		else
			sprintf(cBuf21,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tSerologia&uSerologia=%s>%s</a><td>%s<td><textarea disabled>%s</textarea><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,field[2]
			,field[3]
			,field[4]
			,field[5]
			,field[6]
			,field[7]
			,field[8]
			,field[9]
			,field[10]
			,field[11]
			,field[12]
			,field[13]
			,field[14]
			,field[15]
			,field[16]
			,cBuf17
			,cBuf18
			,cBuf19
			,cBuf20
			,cBuf21
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tSerologiaList()


void CreatetSerologia(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tSerologia ("
		"uSerologia INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"cNotas TEXT NOT NULL DEFAULT '',"
		"uHVAIgM INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVAIgG INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHBVsAg INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVBanticoreIgM INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVBanticoreIgG INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHVC INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCMVIgM INT UNSIGNED NOT NULL DEFAULT 0,"
		"uToxoIgM INT UNSIGNED NOT NULL DEFAULT 0,"
		"uToxoIgG INT UNSIGNED NOT NULL DEFAULT 0,"
		"uChagas INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHIV INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCVHIV INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCVHVC INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCVHVB INT UNSIGNED NOT NULL DEFAULT 0,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetSerologia(void)



