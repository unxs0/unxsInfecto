/*
FILE
	tmedico.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tmedicofunc.h
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
static unsigned uMedico=0;
static char cLabel[33]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tMedico "tMedico.uMedico,tMedico.cLabel,tMedico.uOwner,tMedico.uCreatedBy,tMedico.uCreatedDate,tMedico.uModBy,tMedico.uModDate"

 //Local only
void Insert_tMedico(void);
void Update_tMedico(char *cRowid);
void ProcesstMedicoListVars(pentry entries[], int x);

 //In tMedicofunc.h file included below
void ExtProcesstMedicoVars(pentry entries[], int x);
void ExttMedicoCommands(pentry entries[], int x);
void ExttMedicoButtons(void);
void ExttMedicoNavBar(void);
void ExttMedicoGetHook(entry gentries[], int x);
void ExttMedicoSelect(void);
void ExttMedicoSelectRow(void);
void ExttMedicoListSelect(void);
void ExttMedicoListFilter(void);
void ExttMedicoAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tmedicofunc.h"

 //Table Variables Assignment Function
void ProcesstMedicoVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uMedico"))
			sscanf(entries[i].val,"%u",&uMedico);
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
	ExtProcesstMedicoVars(entries,x);

}//ProcesstMedicoVars()


void ProcesstMedicoListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstMedicoListVars(pentry entries[], int x)


int tMedicoCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttMedicoCommands(entries,x);

	if(!strcmp(gcFunction,"tMedicoTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tMedicoList();
		}

		//Default
		ProcesstMedicoVars(entries,x);
		tMedico("");
	}
	else if(!strcmp(gcFunction,"tMedicoList"))
	{
		ProcessControlVars(entries,x);
		ProcesstMedicoListVars(entries,x);
		tMedicoList();
	}

	return(0);

}//tMedicoCommands()


void tMedicoInput(unsigned uMode)
{
	
	//uMedico uRADType=1001
	OpenRow(LANG_FL_tMedico_uMedico,"black");
	printf("<input title='%s' type=text name=uMedico value='%u' size=16 maxlength=10 "
		,LANG_FT_tMedico_uMedico,uMedico);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uMedico value='%u' >\n",uMedico);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tMedico_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tMedico_cLabel,EncodeDoubleQuotes(cLabel));
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
	OpenRow(LANG_FL_tMedico_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMedico_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMedico_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tMedico_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tMedico_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tMedicoInput(unsigned uMode)


void tMedico(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttMedicoSelectRow();
		else
			ExttMedicoSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetMedico();
				unxsSalud("New tMedico table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tMedico WHERE uMedico=%u"
						,uMedico);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uMedico);
		sprintf(cLabel,"%.32s",field[1]);
		sscanf(field[2],"%u",&uOwner);
		sscanf(field[3],"%u",&uCreatedBy);
		sscanf(field[4],"%lu",&uCreatedDate);
		sscanf(field[5],"%u",&uModBy);
		sscanf(field[6],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de medicos",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tMedicoTools>");
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

        ExttMedicoButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tMedico Record Data",100);

	if(guMode==2000 || guMode==2002)
		tMedicoInput(1);
	else
		tMedicoInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttMedicoAuxTable();

	FooterRAD4();

}//end of tMedico();


void NewtMedico(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uMedico FROM tMedico WHERE uMedico=%u",uMedico);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tMedico(LANG_NBR_RECEXISTS);

	Insert_tMedico();
	uMedico=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tMedico",uMedico);
	unxsSaludLog(uMedico,"tMedico","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uMedico);
		tMedico(gcQuery);
	}

}//NewtMedico(unsigned uMode)


void DeletetMedico(void)
{
	sprintf(gcQuery,"DELETE FROM tMedico WHERE uMedico=%u AND ( uOwner=%u OR %u>9 )"
					,uMedico,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uMedico,"tMedico","Del");
		tMedico(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uMedico,"tMedico","DelError");
		tMedico(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetMedico(void)


void Insert_tMedico(void)
{
	sprintf(gcQuery,"INSERT INTO tMedico SET "
		"cLabel='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tMedico(void)


void Update_tMedico(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tMedico SET "
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

}//void Update_tMedico(void)


void ModtMedico(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tMedico.uMedico,"
				" tMedico.uModDate"
				" FROM tMedico,tClient"
				" WHERE tMedico.uMedico=%u"
				" AND tMedico.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uMedico,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uMedico,uModDate FROM tMedico"
				" WHERE uMedico=%u"
					,uMedico);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tMedico(LANG_NBR_RECNOTEXIST);
	if(i>1) tMedico(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tMedico(LANG_NBR_EXTMOD);

	Update_tMedico(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tMedico",uMedico);
	unxsSaludLog(uMedico,"tMedico","Mod");
	tMedico(gcQuery);

}//ModtMedico(void)


void tMedicoList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttMedicoListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tMedicoList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttMedicoListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uMedico"
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
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tMedico&uMedico=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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

}//tMedicoList()


void CreatetMedico(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tMedico ("
		"uMedico INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetMedico(void)



