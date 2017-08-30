/*
FILE
	tpaciente.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tpacientefunc.h
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
static unsigned uPaciente=0;
static char cLabel[33]={""};
static char cNombre[65]={""};
static char cApellido[65]={""};
static unsigned uStatus=0;
static char cuStatusPullDown[256]={""};
static unsigned uEdad=0;
static char dFechaNacimiento[20]={"01/01/1900"};
static unsigned uAfiliado=0;
static char cDireccion[101]={""};
static char cEmail[101]={""};
static char cTelefonoFijo[65]={""};
static char cTelefonoCelular[65]={""};
static char cDocumento[65]={""};
static char cTipoDocumento[33]={""};
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tPaciente "tPaciente.uPaciente,tPaciente.cLabel,tPaciente.cNombre,tPaciente.cApellido,tPaciente.uStatus,tPaciente.uEdad,DATE_FORMAT(tPaciente.dFechaNacimiento,'%d/%m/%Y'),tPaciente.uAfiliado,tPaciente.cDireccion,tPaciente.cEmail,tPaciente.cTelefonoFijo,tPaciente.cTelefonoCelular,tPaciente.cDocumento,tPaciente.cTipoDocumento,tPaciente.uOwner,tPaciente.uCreatedBy,tPaciente.uCreatedDate,tPaciente.uModBy,tPaciente.uModDate"

 //Local only
void Insert_tPaciente(void);
void Update_tPaciente(char *cRowid);
void ProcesstPacienteListVars(pentry entries[], int x);

 //In tPacientefunc.h file included below
void ExtProcesstPacienteVars(pentry entries[], int x);
void ExttPacienteCommands(pentry entries[], int x);
void ExttPacienteButtons(void);
void ExttPacienteNavBar(void);
void ExttPacienteGetHook(entry gentries[], int x);
void ExttPacienteSelect(void);
void ExttPacienteSelectRow(void);
void ExttPacienteListSelect(void);
void ExttPacienteListFilter(void);
void ExttPacienteAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tpacientefunc.h"

 //Table Variables Assignment Function
void ProcesstPacienteVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uPaciente"))
			sscanf(entries[i].val,"%u",&uPaciente);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"cNombre"))
			sprintf(cNombre,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cApellido"))
			sprintf(cApellido,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"uStatus"))
			sscanf(entries[i].val,"%u",&uStatus);
		else if(!strcmp(entries[i].name,"cuStatusPullDown"))
		{
			sprintf(cuStatusPullDown,"%.255s",entries[i].val);
			uStatus=ReadPullDown("tStatus","cLabel",cuStatusPullDown);
		}
		else if(!strcmp(entries[i].name,"uEdad"))
			sscanf(entries[i].val,"%u",&uEdad);
		else if(!strcmp(entries[i].name,"dFechaNacimiento"))
			sprintf(dFechaNacimiento,"%.10s",entries[i].val);
		else if(!strcmp(entries[i].name,"uAfiliado"))
			sscanf(entries[i].val,"%u",&uAfiliado);
		else if(!strcmp(entries[i].name,"cDireccion"))
			sprintf(cDireccion,"%.100s",entries[i].val);
		else if(!strcmp(entries[i].name,"cEmail"))
			sprintf(cEmail,"%.100s",entries[i].val);
		else if(!strcmp(entries[i].name,"cTelefonoFijo"))
			sprintf(cTelefonoFijo,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cTelefonoCelular"))
			sprintf(cTelefonoCelular,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cDocumento"))
			sprintf(cDocumento,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cTipoDocumento"))
			sprintf(cTipoDocumento,"%.32s",entries[i].val);
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
	ExtProcesstPacienteVars(entries,x);

}//ProcesstPacienteVars()


void ProcesstPacienteListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstPacienteListVars(pentry entries[], int x)


int tPacienteCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttPacienteCommands(entries,x);

	if(!strcmp(gcFunction,"tPacienteTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tPacienteList();
		}

		//Default
		ProcesstPacienteVars(entries,x);
		tPaciente("");
	}
	else if(!strcmp(gcFunction,"tPacienteList"))
	{
		ProcessControlVars(entries,x);
		ProcesstPacienteListVars(entries,x);
		tPacienteList();
	}

	return(0);

}//tPacienteCommands()


void tPacienteInput(unsigned uMode)
{
	
	//uPaciente uRADType=1001
	OpenRow(LANG_FL_tPaciente_uPaciente,"black");
	printf("<input title='%s' type=text name=uPaciente value='%u' size=16 maxlength=10 "
		,LANG_FT_tPaciente_uPaciente,uPaciente);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uPaciente value='%u' >\n",uPaciente);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tPaciente_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tPaciente_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//cNombre uRADType=253
	OpenRow(LANG_FL_tPaciente_cNombre,"black");
	printf("<input title='%s' type=text name=cNombre value='%s' size=40 maxlength=64 "
		,LANG_FT_tPaciente_cNombre,EncodeDoubleQuotes(cNombre));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cNombre value='%s'>\n",EncodeDoubleQuotes(cNombre));
	}
	//cApellido uRADType=253
	OpenRow(LANG_FL_tPaciente_cApellido,"black");
	printf("<input title='%s' type=text name=cApellido value='%s' size=40 maxlength=64 "
		,LANG_FT_tPaciente_cApellido,EncodeDoubleQuotes(cApellido));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cApellido value='%s'>\n",EncodeDoubleQuotes(cApellido));
	}
	//uStatus COLTYPE_SELECTTABLE
	OpenRow(LANG_FL_tPaciente_uStatus,"black");
	if(guPermLevel>=0 && uMode)
		tTablePullDown("tStatus;cuStatusPullDown","cLabel","cLabel",uStatus,1);
	else
		tTablePullDown("tStatus;cuStatusPullDown","cLabel","cLabel",uStatus,0);
	//uEdad uRADType=3
	OpenRow(LANG_FL_tPaciente_uEdad,"black");
	printf("<input title='%s' type=text name=uEdad value='%u' size=16 maxlength=10 "
		,LANG_FT_tPaciente_uEdad,uEdad);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uEdad value='%u' >\n",uEdad);
	}
	//dFechaNacimiento COLTYPE_DATEEUR
	OpenRow(LANG_FL_tPaciente_dFechaNacimiento,"black");
	if(guPermLevel>=0 && uMode)
		jsCalendarInput("dFechaNacimiento",EncodeDoubleQuotes(dFechaNacimiento),1);
	else
		jsCalendarInput("dFechaNacimiento",EncodeDoubleQuotes(dFechaNacimiento),0);
	//uAfiliado uRADType=3
	OpenRow(LANG_FL_tPaciente_uAfiliado,"black");
	printf("<input title='%s' type=text name=uAfiliado value='%u' size=16 maxlength=10 "
		,LANG_FT_tPaciente_uAfiliado,uAfiliado);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uAfiliado value='%u' >\n",uAfiliado);
	}
	//cDireccion uRADType=253
	OpenRow(LANG_FL_tPaciente_cDireccion,"black");
	printf("<input title='%s' type=text name=cDireccion value='%s' size=40 maxlength=100 "
		,LANG_FT_tPaciente_cDireccion,EncodeDoubleQuotes(cDireccion));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cDireccion value='%s'>\n",EncodeDoubleQuotes(cDireccion));
	}
	//cEmail uRADType=253
	OpenRow(LANG_FL_tPaciente_cEmail,"black");
	printf("<input title='%s' type=text name=cEmail value='%s' size=40 maxlength=100 "
		,LANG_FT_tPaciente_cEmail,EncodeDoubleQuotes(cEmail));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cEmail value='%s'>\n",EncodeDoubleQuotes(cEmail));
	}
	//cTelefonoFijo uRADType=253
	OpenRow(LANG_FL_tPaciente_cTelefonoFijo,"black");
	printf("<input title='%s' type=text name=cTelefonoFijo value='%s' size=40 maxlength=64 "
		,LANG_FT_tPaciente_cTelefonoFijo,EncodeDoubleQuotes(cTelefonoFijo));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cTelefonoFijo value='%s'>\n",EncodeDoubleQuotes(cTelefonoFijo));
	}
	//cTelefonoCelular uRADType=253
	OpenRow(LANG_FL_tPaciente_cTelefonoCelular,"black");
	printf("<input title='%s' type=text name=cTelefonoCelular value='%s' size=40 maxlength=64 "
		,LANG_FT_tPaciente_cTelefonoCelular,EncodeDoubleQuotes(cTelefonoCelular));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cTelefonoCelular value='%s'>\n",EncodeDoubleQuotes(cTelefonoCelular));
	}
	//cDocumento uRADType=253
	OpenRow(LANG_FL_tPaciente_cDocumento,"black");
	printf("<input title='%s' type=text name=cDocumento value='%s' size=40 maxlength=64 "
		,LANG_FT_tPaciente_cDocumento,EncodeDoubleQuotes(cDocumento));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cDocumento value='%s'>\n",EncodeDoubleQuotes(cDocumento));
	}
	//cTipoDocumento uRADType=253
	OpenRow(LANG_FL_tPaciente_cTipoDocumento,"black");
	printf("<input title='%s' type=text name=cTipoDocumento value='%s' size=40 maxlength=32 "
		,LANG_FT_tPaciente_cTipoDocumento,EncodeDoubleQuotes(cTipoDocumento));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cTipoDocumento value='%s'>\n",EncodeDoubleQuotes(cTipoDocumento));
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tPaciente_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tPaciente_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tPaciente_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tPaciente_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tPaciente_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tPacienteInput(unsigned uMode)


void tPaciente(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttPacienteSelectRow();
		else
			ExttPacienteSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetPaciente();
				unxsSalud("New tPaciente table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tPaciente WHERE uPaciente=%u"
						,uPaciente);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uPaciente);
		sprintf(cLabel,"%.32s",field[1]);
		sprintf(cNombre,"%.64s",field[2]);
		sprintf(cApellido,"%.64s",field[3]);
		sscanf(field[4],"%u",&uStatus);
		sscanf(field[5],"%u",&uEdad);
		sprintf(dFechaNacimiento,"%.10s",field[6]);
		sscanf(field[7],"%u",&uAfiliado);
		sprintf(cDireccion,"%.100s",field[8]);
		sprintf(cEmail,"%.100s",field[9]);
		sprintf(cTelefonoFijo,"%.64s",field[10]);
		sprintf(cTelefonoCelular,"%.64s",field[11]);
		sprintf(cDocumento,"%.64s",field[12]);
		sprintf(cTipoDocumento,"%.32s",field[13]);
		sscanf(field[14],"%u",&uOwner);
		sscanf(field[15],"%u",&uCreatedBy);
		sscanf(field[16],"%lu",&uCreatedDate);
		sscanf(field[17],"%u",&uModBy);
		sscanf(field[18],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Pacientes",1);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tPacienteTools>");
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

        ExttPacienteButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tPaciente Record Data",100);

	if(guMode==2000 || guMode==2002)
		tPacienteInput(1);
	else
		tPacienteInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttPacienteAuxTable();

	FooterRAD4();

}//end of tPaciente();


void NewtPaciente(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uPaciente FROM tPaciente WHERE uPaciente=%u",uPaciente);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tPaciente(LANG_NBR_RECEXISTS);

	Insert_tPaciente();
	uPaciente=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tPaciente",uPaciente);
	unxsSaludLog(uPaciente,"tPaciente","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uPaciente);
		tPaciente(gcQuery);
	}

}//NewtPaciente(unsigned uMode)


void DeletetPaciente(void)
{
	sprintf(gcQuery,"DELETE FROM tPaciente WHERE uPaciente=%u AND ( uOwner=%u OR %u>9 )"
					,uPaciente,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uPaciente,"tPaciente","Del");
		tPaciente(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uPaciente,"tPaciente","DelError");
		tPaciente(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetPaciente(void)


void Insert_tPaciente(void)
{
	sprintf(gcQuery,"INSERT INTO tPaciente SET "
		"cLabel='%s',"
		"cNombre='%s',"
		"cApellido='%s',"
		"uStatus=%u,"
		"uEdad=%u,"
		"dFechaNacimiento=STR_TO_DATE('%s','%%d/%%m/%%Y'),"
		"uAfiliado=%u,"
		"cDireccion='%s',"
		"cEmail='%s',"
		"cTelefonoFijo='%s',"
		"cTelefonoCelular='%s',"
		"cDocumento='%s',"
		"cTipoDocumento='%s',"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,TextAreaSave(cNombre)
			,TextAreaSave(cApellido)
			,uStatus
			,uEdad
			,TextAreaSave(dFechaNacimiento)
			,uAfiliado
			,TextAreaSave(cDireccion)
			,TextAreaSave(cEmail)
			,TextAreaSave(cTelefonoFijo)
			,TextAreaSave(cTelefonoCelular)
			,TextAreaSave(cDocumento)
			,TextAreaSave(cTipoDocumento)
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tPaciente(void)


void Update_tPaciente(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tPaciente SET "
		"cLabel='%s',"
		"cNombre='%s',"
		"cApellido='%s',"
		"uStatus=%u,"
		"uEdad=%u,"
		"dFechaNacimiento=STR_TO_DATE('%s','%%d/%%m/%%Y'),"
		"uAfiliado=%u,"
		"cDireccion='%s',"
		"cEmail='%s',"
		"cTelefonoFijo='%s',"
		"cTelefonoCelular='%s',"
		"cDocumento='%s',"
		"cTipoDocumento='%s',"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,TextAreaSave(cNombre)
			,TextAreaSave(cApellido)
			,uStatus
			,uEdad
			,TextAreaSave(dFechaNacimiento)
			,uAfiliado
			,TextAreaSave(cDireccion)
			,TextAreaSave(cEmail)
			,TextAreaSave(cTelefonoFijo)
			,TextAreaSave(cTelefonoCelular)
			,TextAreaSave(cDocumento)
			,TextAreaSave(cTipoDocumento)
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tPaciente(void)


void ModtPaciente(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tPaciente.uPaciente,"
				" tPaciente.uModDate"
				" FROM tPaciente,tClient"
				" WHERE tPaciente.uPaciente=%u"
				" AND tPaciente.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uPaciente,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uPaciente,uModDate FROM tPaciente"
				" WHERE uPaciente=%u"
					,uPaciente);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tPaciente(LANG_NBR_RECNOTEXIST);
	if(i>1) tPaciente(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tPaciente(LANG_NBR_EXTMOD);

	Update_tPaciente(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tPaciente",uPaciente);
	unxsSaludLog(uPaciente,"tPaciente","Mod");
	tPaciente(gcQuery);

}//ModtPaciente(void)


void tPacienteList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttPacienteListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tPacienteList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttPacienteListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uPaciente"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>cNombre"
		"<td><font face=arial,helvetica color=white>cApellido"
		"<td><font face=arial,helvetica color=white>uStatus"
		"<td><font face=arial,helvetica color=white>uEdad"
		"<td><font face=arial,helvetica color=white>dFechaNacimiento"
		"<td><font face=arial,helvetica color=white>uAfiliado"
		"<td><font face=arial,helvetica color=white>cDireccion"
		"<td><font face=arial,helvetica color=white>cEmail"
		"<td><font face=arial,helvetica color=white>cTelefonoFijo"
		"<td><font face=arial,helvetica color=white>cTelefonoCelular"
		"<td><font face=arial,helvetica color=white>cDocumento"
		"<td><font face=arial,helvetica color=white>cTipoDocumento"
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
				char cBuf4[128];
		sprintf(cBuf4,"<a class=darkLink href=?gcFunction=tStatus&uStatus=%.32s>%.32s</a>",
			field[4],
			ForeignKey("tStatus","cLabel",strtoul(field[4],NULL,10)));
		char cBuf14[128];
		sprintf(cBuf14,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[14],
			ForeignKey("tClient","cLabel",strtoul(field[14],NULL,10)));
		char cBuf15[128];
		sprintf(cBuf15,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[15],
			ForeignKey("tClient","cLabel",strtoul(field[15],NULL,10)));
		time_t luTime16=strtoul(field[16],NULL,10);
		char cBuf16[32];
		if(luTime16)
			ctime_r(&luTime16,cBuf16);
		else
			sprintf(cBuf16,"---");
		char cBuf17[128];
		sprintf(cBuf17,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[17],
			ForeignKey("tClient","cLabel",strtoul(field[17],NULL,10)));
		time_t luTime18=strtoul(field[18],NULL,10);
		char cBuf18[32];
		if(luTime18)
			ctime_r(&luTime18,cBuf18);
		else
			sprintf(cBuf18,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tPaciente&uPaciente=%s>%s</a><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
			,field[0]
			,field[0]
			,field[1]
			,field[2]
			,field[3]
			,cBuf4
			,field[5]
			,field[6]
			,field[7]
			,field[8]
			,field[9]
			,field[10]
			,field[11]
			,field[12]
			,field[13]
			,cBuf14
			,cBuf15
			,cBuf16
			,cBuf17
			,cBuf18
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tPacienteList()


void CreatetPaciente(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tPaciente ("
		"uPaciente INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"cNombre VARCHAR(64) NOT NULL DEFAULT '',"
		"cApellido VARCHAR(64) NOT NULL DEFAULT '',"
		"uStatus INT UNSIGNED NOT NULL DEFAULT 0,"
		"uEdad INT UNSIGNED NOT NULL DEFAULT 0,"
		"dFechaNacimiento DATETIME NOT NULL,"
		"uAfiliado INT UNSIGNED NOT NULL DEFAULT 0,"
		"cDireccion VARCHAR(100) NOT NULL DEFAULT '',"
		"cEmail VARCHAR(100) NOT NULL DEFAULT '',"
		"cTelefonoFijo VARCHAR(64) NOT NULL DEFAULT '',"
		"cTelefonoCelular VARCHAR(64) NOT NULL DEFAULT '',"
		"cDocumento VARCHAR(64) NOT NULL DEFAULT '',"
		"cTipoDocumento VARCHAR(32) NOT NULL DEFAULT '',"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetPaciente(void)



