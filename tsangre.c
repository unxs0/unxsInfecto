/*
FILE
	tsangre.c
	From unxsRAD RAD4 module.c template
PURPOSE
	Schema dependent RAD generated file.
	Program app functionality can be developed in tsangrefunc.h
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
static unsigned uSangre=0;
static char cLabel[33]={""};
static char cLaboratorio[65]={""};
static char *cOtro={""};
static unsigned uLDH=0;
static unsigned uUrea=0;
static unsigned uHb=0;
static unsigned uHematocrito=0;
static unsigned uLeucocitos=0;
static unsigned uNeutrofilos=0;
static unsigned uBasofilos=0;
static unsigned uEosinofilos=0;
static unsigned uLinfocitos=0;
static unsigned uMonocitos=0;
static unsigned uGlobulosRojos=0;
static unsigned uPlaquetas=0;
static unsigned uCreatinina=0;
static unsigned uGlucemia=0;
static unsigned uPCR=0;
static unsigned uVSG=0;
static unsigned uTGO=0;
static unsigned uTGP=0;
static unsigned uGGT=0;
static unsigned uBilT=0;
static unsigned uBilD=0;
static unsigned uCPK=0;
static unsigned uSodio=0;
static unsigned uPotasio=0;
static unsigned uCloro=0;
static unsigned uTSH=0;
static unsigned uT4=0;
static unsigned uT3=0;
static unsigned uAlbumina=0;
static unsigned uFAL=0;
static unsigned uAmilasa=0;
static unsigned uCD4=0;
static unsigned uCD8=0;
static unsigned uOwner=0;
#define StandardFields
static unsigned uCreatedBy=0;
static time_t uCreatedDate=0;
static unsigned uModBy=0;
static time_t uModDate=0;


#define VAR_LIST_tSangre "tSangre.uSangre,tSangre.cLabel,tSangre.cLaboratorio,tSangre.cOtro,tSangre.uLDH,tSangre.uUrea,tSangre.uHb,tSangre.uHematocrito,tSangre.uLeucocitos,tSangre.uNeutrofilos,tSangre.uBasofilos,tSangre.uEosinofilos,tSangre.uLinfocitos,tSangre.uMonocitos,tSangre.uGlobulosRojos,tSangre.uPlaquetas,tSangre.uCreatinina,tSangre.uGlucemia,tSangre.uPCR,tSangre.uVSG,tSangre.uTGO,tSangre.uTGP,tSangre.uGGT,tSangre.uBilT,tSangre.uBilD,tSangre.uCPK,tSangre.uSodio,tSangre.uPotasio,tSangre.uCloro,tSangre.uTSH,tSangre.uT4,tSangre.uT3,tSangre.uAlbumina,tSangre.uFAL,tSangre.uAmilasa,tSangre.uCD4,tSangre.uCD8,tSangre.uOwner,tSangre.uCreatedBy,tSangre.uCreatedDate,tSangre.uModBy,tSangre.uModDate"

 //Local only
void Insert_tSangre(void);
void Update_tSangre(char *cRowid);
void ProcesstSangreListVars(pentry entries[], int x);

 //In tSangrefunc.h file included below
void ExtProcesstSangreVars(pentry entries[], int x);
void ExttSangreCommands(pentry entries[], int x);
void ExttSangreButtons(void);
void ExttSangreNavBar(void);
void ExttSangreGetHook(entry gentries[], int x);
void ExttSangreSelect(void);
void ExttSangreSelectRow(void);
void ExttSangreListSelect(void);
void ExttSangreListFilter(void);
void ExttSangreAuxTable(void);

char static *sgcBuildInfo="39e92f3-dirty";

#include "tsangrefunc.h"

 //Table Variables Assignment Function
void ProcesstSangreVars(pentry entries[], int x)
{
	register int i;


	for(i=0;i<x;i++)
	{
		
		if(!strcmp(entries[i].name,"uSangre"))
			sscanf(entries[i].val,"%u",&uSangre);
		else if(!strcmp(entries[i].name,"cLabel"))
			sprintf(cLabel,"%.32s",entries[i].val);
		else if(!strcmp(entries[i].name,"cLaboratorio"))
			sprintf(cLaboratorio,"%.64s",entries[i].val);
		else if(!strcmp(entries[i].name,"cOtro"))
			cOtro=entries[i].val;
		else if(!strcmp(entries[i].name,"uLDH"))
			sscanf(entries[i].val,"%u",&uLDH);
		else if(!strcmp(entries[i].name,"uUrea"))
			sscanf(entries[i].val,"%u",&uUrea);
		else if(!strcmp(entries[i].name,"uHb"))
			sscanf(entries[i].val,"%u",&uHb);
		else if(!strcmp(entries[i].name,"uHematocrito"))
			sscanf(entries[i].val,"%u",&uHematocrito);
		else if(!strcmp(entries[i].name,"uLeucocitos"))
			sscanf(entries[i].val,"%u",&uLeucocitos);
		else if(!strcmp(entries[i].name,"uNeutrofilos"))
			sscanf(entries[i].val,"%u",&uNeutrofilos);
		else if(!strcmp(entries[i].name,"uBasofilos"))
			sscanf(entries[i].val,"%u",&uBasofilos);
		else if(!strcmp(entries[i].name,"uEosinofilos"))
			sscanf(entries[i].val,"%u",&uEosinofilos);
		else if(!strcmp(entries[i].name,"uLinfocitos"))
			sscanf(entries[i].val,"%u",&uLinfocitos);
		else if(!strcmp(entries[i].name,"uMonocitos"))
			sscanf(entries[i].val,"%u",&uMonocitos);
		else if(!strcmp(entries[i].name,"uGlobulosRojos"))
			sscanf(entries[i].val,"%u",&uGlobulosRojos);
		else if(!strcmp(entries[i].name,"uPlaquetas"))
			sscanf(entries[i].val,"%u",&uPlaquetas);
		else if(!strcmp(entries[i].name,"uCreatinina"))
			sscanf(entries[i].val,"%u",&uCreatinina);
		else if(!strcmp(entries[i].name,"uGlucemia"))
			sscanf(entries[i].val,"%u",&uGlucemia);
		else if(!strcmp(entries[i].name,"uPCR"))
			sscanf(entries[i].val,"%u",&uPCR);
		else if(!strcmp(entries[i].name,"uVSG"))
			sscanf(entries[i].val,"%u",&uVSG);
		else if(!strcmp(entries[i].name,"uTGO"))
			sscanf(entries[i].val,"%u",&uTGO);
		else if(!strcmp(entries[i].name,"uTGP"))
			sscanf(entries[i].val,"%u",&uTGP);
		else if(!strcmp(entries[i].name,"uGGT"))
			sscanf(entries[i].val,"%u",&uGGT);
		else if(!strcmp(entries[i].name,"uBilT"))
			sscanf(entries[i].val,"%u",&uBilT);
		else if(!strcmp(entries[i].name,"uBilD"))
			sscanf(entries[i].val,"%u",&uBilD);
		else if(!strcmp(entries[i].name,"uCPK"))
			sscanf(entries[i].val,"%u",&uCPK);
		else if(!strcmp(entries[i].name,"uSodio"))
			sscanf(entries[i].val,"%u",&uSodio);
		else if(!strcmp(entries[i].name,"uPotasio"))
			sscanf(entries[i].val,"%u",&uPotasio);
		else if(!strcmp(entries[i].name,"uCloro"))
			sscanf(entries[i].val,"%u",&uCloro);
		else if(!strcmp(entries[i].name,"uTSH"))
			sscanf(entries[i].val,"%u",&uTSH);
		else if(!strcmp(entries[i].name,"uT4"))
			sscanf(entries[i].val,"%u",&uT4);
		else if(!strcmp(entries[i].name,"uT3"))
			sscanf(entries[i].val,"%u",&uT3);
		else if(!strcmp(entries[i].name,"uAlbumina"))
			sscanf(entries[i].val,"%u",&uAlbumina);
		else if(!strcmp(entries[i].name,"uFAL"))
			sscanf(entries[i].val,"%u",&uFAL);
		else if(!strcmp(entries[i].name,"uAmilasa"))
			sscanf(entries[i].val,"%u",&uAmilasa);
		else if(!strcmp(entries[i].name,"uCD4"))
			sscanf(entries[i].val,"%u",&uCD4);
		else if(!strcmp(entries[i].name,"uCD8"))
			sscanf(entries[i].val,"%u",&uCD8);
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
	ExtProcesstSangreVars(entries,x);

}//ProcesstSangreVars()


void ProcesstSangreListVars(pentry entries[], int x)
{
        //register int i;
        //for(i=0;i<x;i++)
        //{
        //	if(!strcmp(entries[i].name,"example"))
        //	{
        //	}
        //}
}//void ProcesstSangreListVars(pentry entries[], int x)


int tSangreCommands(pentry entries[], int x)
{
	ProcessControlVars(entries,x);

	ExttSangreCommands(entries,x);

	if(!strcmp(gcFunction,"tSangreTools"))
	{
		if(!strcmp(gcFind,LANG_NB_LIST))
		{
			tSangreList();
		}

		//Default
		ProcesstSangreVars(entries,x);
		tSangre("");
	}
	else if(!strcmp(gcFunction,"tSangreList"))
	{
		ProcessControlVars(entries,x);
		ProcesstSangreListVars(entries,x);
		tSangreList();
	}

	return(0);

}//tSangreCommands()


void tSangreInput(unsigned uMode)
{
	
	//uSangre uRADType=1001
	OpenRow(LANG_FL_tSangre_uSangre,"black");
	printf("<input title='%s' type=text name=uSangre value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uSangre,uSangre);
	if(guPermLevel>=20 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uSangre value='%u' >\n",uSangre);
	}
	//cLabel uRADType=253
	OpenRow(LANG_FL_tSangre_cLabel,"black");
	printf("<input title='%s' type=text name=cLabel value='%s' size=40 maxlength=32 "
		,LANG_FT_tSangre_cLabel,EncodeDoubleQuotes(cLabel));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLabel value='%s'>\n",EncodeDoubleQuotes(cLabel));
	}
	//cLaboratorio uRADType=253
	OpenRow(LANG_FL_tSangre_cLaboratorio,"black");
	printf("<input title='%s' type=text name=cLaboratorio value='%s' size=0 maxlength=0 "
		,LANG_FT_tSangre_cLaboratorio,EncodeDoubleQuotes(cLaboratorio));
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=cLaboratorio value='%s'>\n",EncodeDoubleQuotes(cLaboratorio));
	}
	//cOtro COLTYPE_TEXT
	OpenRow(LANG_FL_tSangre_cOtro,"black");
	printf("<textarea title='%s' cols=80 wrap=hard rows=16 name=cOtro "
,LANG_FT_tSangre_cOtro);
	if(guPermLevel>=0 && uMode)
	{
		printf(">%s</textarea></td></tr>\n",cOtro);
	}
	else
	{
		printf("disabled>%s</textarea></td></tr>\n",cOtro);
		printf("<input type=hidden name=cOtro value=\"%s\" >\n",EncodeDoubleQuotes(cOtro));
	}
	//uLDH uRADType=3
	OpenRow(LANG_FL_tSangre_uLDH,"black");
	printf("<input title='%s' type=text name=uLDH value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uLDH,uLDH);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uLDH value='%u' >\n",uLDH);
	}
	//uUrea uRADType=3
	OpenRow(LANG_FL_tSangre_uUrea,"black");
	printf("<input title='%s' type=text name=uUrea value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uUrea,uUrea);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uUrea value='%u' >\n",uUrea);
	}
	//uHb uRADType=3
	OpenRow(LANG_FL_tSangre_uHb,"black");
	printf("<input title='%s' type=text name=uHb value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uHb,uHb);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHb value='%u' >\n",uHb);
	}
	//uHematocrito uRADType=3
	OpenRow(LANG_FL_tSangre_uHematocrito,"black");
	printf("<input title='%s' type=text name=uHematocrito value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uHematocrito,uHematocrito);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uHematocrito value='%u' >\n",uHematocrito);
	}
	//uLeucocitos uRADType=3
	OpenRow(LANG_FL_tSangre_uLeucocitos,"black");
	printf("<input title='%s' type=text name=uLeucocitos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uLeucocitos,uLeucocitos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uLeucocitos value='%u' >\n",uLeucocitos);
	}
	//uNeutrofilos uRADType=3
	OpenRow(LANG_FL_tSangre_uNeutrofilos,"black");
	printf("<input title='%s' type=text name=uNeutrofilos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uNeutrofilos,uNeutrofilos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uNeutrofilos value='%u' >\n",uNeutrofilos);
	}
	//uBasofilos uRADType=3
	OpenRow(LANG_FL_tSangre_uBasofilos,"black");
	printf("<input title='%s' type=text name=uBasofilos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uBasofilos,uBasofilos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uBasofilos value='%u' >\n",uBasofilos);
	}
	//uEosinofilos uRADType=3
	OpenRow(LANG_FL_tSangre_uEosinofilos,"black");
	printf("<input title='%s' type=text name=uEosinofilos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uEosinofilos,uEosinofilos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uEosinofilos value='%u' >\n",uEosinofilos);
	}
	//uLinfocitos uRADType=3
	OpenRow(LANG_FL_tSangre_uLinfocitos,"black");
	printf("<input title='%s' type=text name=uLinfocitos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uLinfocitos,uLinfocitos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uLinfocitos value='%u' >\n",uLinfocitos);
	}
	//uMonocitos uRADType=3
	OpenRow(LANG_FL_tSangre_uMonocitos,"black");
	printf("<input title='%s' type=text name=uMonocitos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uMonocitos,uMonocitos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uMonocitos value='%u' >\n",uMonocitos);
	}
	//uGlobulosRojos uRADType=3
	OpenRow(LANG_FL_tSangre_uGlobulosRojos,"black");
	printf("<input title='%s' type=text name=uGlobulosRojos value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uGlobulosRojos,uGlobulosRojos);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uGlobulosRojos value='%u' >\n",uGlobulosRojos);
	}
	//uPlaquetas uRADType=3
	OpenRow(LANG_FL_tSangre_uPlaquetas,"black");
	printf("<input title='%s' type=text name=uPlaquetas value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uPlaquetas,uPlaquetas);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uPlaquetas value='%u' >\n",uPlaquetas);
	}
	//uCreatinina uRADType=3
	OpenRow(LANG_FL_tSangre_uCreatinina,"black");
	printf("<input title='%s' type=text name=uCreatinina value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uCreatinina,uCreatinina);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCreatinina value='%u' >\n",uCreatinina);
	}
	//uGlucemia uRADType=3
	OpenRow(LANG_FL_tSangre_uGlucemia,"black");
	printf("<input title='%s' type=text name=uGlucemia value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uGlucemia,uGlucemia);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uGlucemia value='%u' >\n",uGlucemia);
	}
	//uPCR uRADType=3
	OpenRow(LANG_FL_tSangre_uPCR,"black");
	printf("<input title='%s' type=text name=uPCR value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uPCR,uPCR);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uPCR value='%u' >\n",uPCR);
	}
	//uVSG uRADType=3
	OpenRow(LANG_FL_tSangre_uVSG,"black");
	printf("<input title='%s' type=text name=uVSG value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uVSG,uVSG);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uVSG value='%u' >\n",uVSG);
	}
	//uTGO uRADType=3
	OpenRow(LANG_FL_tSangre_uTGO,"black");
	printf("<input title='%s' type=text name=uTGO value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uTGO,uTGO);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTGO value='%u' >\n",uTGO);
	}
	//uTGP uRADType=3
	OpenRow(LANG_FL_tSangre_uTGP,"black");
	printf("<input title='%s' type=text name=uTGP value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uTGP,uTGP);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTGP value='%u' >\n",uTGP);
	}
	//uGGT uRADType=3
	OpenRow(LANG_FL_tSangre_uGGT,"black");
	printf("<input title='%s' type=text name=uGGT value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uGGT,uGGT);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uGGT value='%u' >\n",uGGT);
	}
	//uBilT uRADType=3
	OpenRow(LANG_FL_tSangre_uBilT,"black");
	printf("<input title='%s' type=text name=uBilT value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uBilT,uBilT);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uBilT value='%u' >\n",uBilT);
	}
	//uBilD uRADType=3
	OpenRow(LANG_FL_tSangre_uBilD,"black");
	printf("<input title='%s' type=text name=uBilD value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uBilD,uBilD);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uBilD value='%u' >\n",uBilD);
	}
	//uCPK uRADType=3
	OpenRow(LANG_FL_tSangre_uCPK,"black");
	printf("<input title='%s' type=text name=uCPK value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uCPK,uCPK);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCPK value='%u' >\n",uCPK);
	}
	//uSodio uRADType=3
	OpenRow(LANG_FL_tSangre_uSodio,"black");
	printf("<input title='%s' type=text name=uSodio value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uSodio,uSodio);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uSodio value='%u' >\n",uSodio);
	}
	//uPotasio uRADType=3
	OpenRow(LANG_FL_tSangre_uPotasio,"black");
	printf("<input title='%s' type=text name=uPotasio value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uPotasio,uPotasio);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uPotasio value='%u' >\n",uPotasio);
	}
	//uCloro uRADType=3
	OpenRow(LANG_FL_tSangre_uCloro,"black");
	printf("<input title='%s' type=text name=uCloro value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uCloro,uCloro);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCloro value='%u' >\n",uCloro);
	}
	//uTSH uRADType=3
	OpenRow(LANG_FL_tSangre_uTSH,"black");
	printf("<input title='%s' type=text name=uTSH value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uTSH,uTSH);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uTSH value='%u' >\n",uTSH);
	}
	//uT4 uRADType=3
	OpenRow(LANG_FL_tSangre_uT4,"black");
	printf("<input title='%s' type=text name=uT4 value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uT4,uT4);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uT4 value='%u' >\n",uT4);
	}
	//uT3 uRADType=3
	OpenRow(LANG_FL_tSangre_uT3,"black");
	printf("<input title='%s' type=text name=uT3 value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uT3,uT3);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uT3 value='%u' >\n",uT3);
	}
	//uAlbumina uRADType=3
	OpenRow(LANG_FL_tSangre_uAlbumina,"black");
	printf("<input title='%s' type=text name=uAlbumina value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uAlbumina,uAlbumina);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uAlbumina value='%u' >\n",uAlbumina);
	}
	//uFAL uRADType=3
	OpenRow(LANG_FL_tSangre_uFAL,"black");
	printf("<input title='%s' type=text name=uFAL value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uFAL,uFAL);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uFAL value='%u' >\n",uFAL);
	}
	//uAmilasa uRADType=3
	OpenRow(LANG_FL_tSangre_uAmilasa,"black");
	printf("<input title='%s' type=text name=uAmilasa value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uAmilasa,uAmilasa);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uAmilasa value='%u' >\n",uAmilasa);
	}
	//uCD4 uRADType=3
	OpenRow(LANG_FL_tSangre_uCD4,"black");
	printf("<input title='%s' type=text name=uCD4 value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uCD4,uCD4);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCD4 value='%u' >\n",uCD4);
	}
	//uCD8 uRADType=3
	OpenRow(LANG_FL_tSangre_uCD8,"black");
	printf("<input title='%s' type=text name=uCD8 value='%u' size=16 maxlength=10 "
		,LANG_FT_tSangre_uCD8,uCD8);
	if(guPermLevel>=0 && uMode)
	{
		printf("></td></tr>\n");
	}
	else
	{
		printf("disabled></td></tr>\n");
		printf("<input type=hidden name=uCD8 value='%u' >\n",uCD8);
	}
	//uOwner COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSangre_uOwner,"black");
	printf("%s<input type=hidden name=uOwner value='%u' >\n",ForeignKey("tClient","cLabel",uOwner),uOwner);
	//uCreatedBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSangre_uCreatedBy,"black");
	printf("%s<input type=hidden name=uCreatedBy value='%u' >\n",ForeignKey("tClient","cLabel",uCreatedBy),uCreatedBy);
	//uCreatedDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tSangre_uCreatedDate,"black");
	if(uCreatedDate)
		printf("%s\n\n",ctime(&uCreatedDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uCreatedDate value='%lu' >\n",uCreatedDate);
	//uModBy COLTYPE_FOREIGNKEY
	OpenRow(LANG_FL_tSangre_uModBy,"black");
	printf("%s<input type=hidden name=uModBy value='%u' >\n",ForeignKey("tClient","cLabel",uModBy),uModBy);
	//uModDate COLTYPE_UNIXTIMECREATE COLTYPE_UNIXTIMEUPDATE
	OpenRow(LANG_FL_tSangre_uModDate,"black");
	if(uModDate)
		printf("%s\n\n",ctime(&uModDate));
	else
		printf("---\n\n");
	printf("<input type=hidden name=uModDate value='%lu' >\n",uModDate);
	printf("</tr>\n");

}//void tSangreInput(unsigned uMode)


void tSangre(const char *cResult)
{
	MYSQL_RES *res;
	MYSQL_RES *res2;
	MYSQL_ROW field;

	//Internal skip reloading
	if(!cResult[0])
	{
		if(guMode)
			ExttSangreSelectRow();
		else
			ExttSangreSelect();

		mysql_query(&gMysql,gcQuery);
		if(mysql_errno(&gMysql))
        	{
			if(strstr(mysql_error(&gMysql)," doesn't exist"))
                	{
				CreatetSangre();
				unxsSalud("New tSangre table created");
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
			sprintf(gcQuery,"SELECT _rowid FROM tSangre WHERE uSangre=%u"
						,uSangre);
				macro_mySQLRunAndStore(res2);
				field=mysql_fetch_row(res2);
				sscanf(field[0],"%lu",&gluRowid);
				gluRowid++;
			}
			PageMachine("",0,"");
			if(!guMode) mysql_data_seek(res,gluRowid-1);
			field=mysql_fetch_row(res);
			
		sscanf(field[0],"%u",&uSangre);
		sprintf(cLabel,"%.32s",field[1]);
		sprintf(cLaboratorio,"%.64s",field[2]);
		cOtro=field[3];
		sscanf(field[4],"%u",&uLDH);
		sscanf(field[5],"%u",&uUrea);
		sscanf(field[6],"%u",&uHb);
		sscanf(field[7],"%u",&uHematocrito);
		sscanf(field[8],"%u",&uLeucocitos);
		sscanf(field[9],"%u",&uNeutrofilos);
		sscanf(field[10],"%u",&uBasofilos);
		sscanf(field[11],"%u",&uEosinofilos);
		sscanf(field[12],"%u",&uLinfocitos);
		sscanf(field[13],"%u",&uMonocitos);
		sscanf(field[14],"%u",&uGlobulosRojos);
		sscanf(field[15],"%u",&uPlaquetas);
		sscanf(field[16],"%u",&uCreatinina);
		sscanf(field[17],"%u",&uGlucemia);
		sscanf(field[18],"%u",&uPCR);
		sscanf(field[19],"%u",&uVSG);
		sscanf(field[20],"%u",&uTGO);
		sscanf(field[21],"%u",&uTGP);
		sscanf(field[22],"%u",&uGGT);
		sscanf(field[23],"%u",&uBilT);
		sscanf(field[24],"%u",&uBilD);
		sscanf(field[25],"%u",&uCPK);
		sscanf(field[26],"%u",&uSodio);
		sscanf(field[27],"%u",&uPotasio);
		sscanf(field[28],"%u",&uCloro);
		sscanf(field[29],"%u",&uTSH);
		sscanf(field[30],"%u",&uT4);
		sscanf(field[31],"%u",&uT3);
		sscanf(field[32],"%u",&uAlbumina);
		sscanf(field[33],"%u",&uFAL);
		sscanf(field[34],"%u",&uAmilasa);
		sscanf(field[35],"%u",&uCD4);
		sscanf(field[36],"%u",&uCD8);
		sscanf(field[37],"%u",&uOwner);
		sscanf(field[38],"%u",&uCreatedBy);
		sscanf(field[39],"%lu",&uCreatedDate);
		sscanf(field[40],"%u",&uModBy);
		sscanf(field[41],"%lu",&uModDate);

		}

	}//Internal Skip

	HeaderRAD4(":: Tabla de Sangre",0);
	printf("<table width=100%% cellspacing=0 cellpadding=0>\n");
	printf("<tr><td colspan=2 align=right valign=center>");


	printf("<input type=hidden name=gcFunction value=tSangreTools>");
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

        ExttSangreButtons();

        printf("</td><td valign=top>");
	//
	OpenFieldSet("tSangre Record Data",100);

	if(guMode==2000 || guMode==2002)
		tSangreInput(1);
	else
		tSangreInput(0);

	//
	CloseFieldSet();

	//Bottom table
	printf("<tr><td colspan=2>");
        ExttSangreAuxTable();

	FooterRAD4();

}//end of tSangre();


void NewtSangre(unsigned uMode)
{
	register int i=0;
	MYSQL_RES *res;

	sprintf(gcQuery,"SELECT uSangre FROM tSangre WHERE uSangre=%u",uSangre);
	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i) 
		tSangre(LANG_NBR_RECEXISTS);

	Insert_tSangre();
	uSangre=mysql_insert_id(&gMysql);
	uCreatedDate=luGetCreatedDate("tSangre",uSangre);
	unxsSaludLog(uSangre,"tSangre","New");

	if(!uMode)
	{
		sprintf(gcQuery,LANG_NBR_NEWRECADDED,uSangre);
		tSangre(gcQuery);
	}

}//NewtSangre(unsigned uMode)


void DeletetSangre(void)
{
	sprintf(gcQuery,"DELETE FROM tSangre WHERE uSangre=%u AND ( uOwner=%u OR %u>9 )"
					,uSangre,guLoginClient,guPermLevel);
	macro_mySQLQueryHTMLError;
	if(mysql_affected_rows(&gMysql)>0)
	{
		unxsSaludLog(uSangre,"tSangre","Del");
		tSangre(LANG_NBR_RECDELETED);
	}
	else
	{
		unxsSaludLog(uSangre,"tSangre","DelError");
		tSangre(LANG_NBR_RECNOTDELETED);
	}

}//void DeletetSangre(void)


void Insert_tSangre(void)
{
	sprintf(gcQuery,"INSERT INTO tSangre SET "
		"cLabel='%s',"
		"cLaboratorio='%s',"
		"cOtro='%s',"
		"uLDH=%u,"
		"uUrea=%u,"
		"uHb=%u,"
		"uHematocrito=%u,"
		"uLeucocitos=%u,"
		"uNeutrofilos=%u,"
		"uBasofilos=%u,"
		"uEosinofilos=%u,"
		"uLinfocitos=%u,"
		"uMonocitos=%u,"
		"uGlobulosRojos=%u,"
		"uPlaquetas=%u,"
		"uCreatinina=%u,"
		"uGlucemia=%u,"
		"uPCR=%u,"
		"uVSG=%u,"
		"uTGO=%u,"
		"uTGP=%u,"
		"uGGT=%u,"
		"uBilT=%u,"
		"uBilD=%u,"
		"uCPK=%u,"
		"uSodio=%u,"
		"uPotasio=%u,"
		"uCloro=%u,"
		"uTSH=%u,"
		"uT4=%u,"
		"uT3=%u,"
		"uAlbumina=%u,"
		"uFAL=%u,"
		"uAmilasa=%u,"
		"uCD4=%u,"
		"uCD8=%u,"
		"uOwner=%u,"
		"uCreatedBy=%u,"
		"uCreatedDate=UNIX_TIMESTAMP(NOW())"
			,TextAreaSave(cLabel)
			,TextAreaSave(cLaboratorio)
			,TextAreaSave(cOtro)
			,uLDH
			,uUrea
			,uHb
			,uHematocrito
			,uLeucocitos
			,uNeutrofilos
			,uBasofilos
			,uEosinofilos
			,uLinfocitos
			,uMonocitos
			,uGlobulosRojos
			,uPlaquetas
			,uCreatinina
			,uGlucemia
			,uPCR
			,uVSG
			,uTGO
			,uTGP
			,uGGT
			,uBilT
			,uBilD
			,uCPK
			,uSodio
			,uPotasio
			,uCloro
			,uTSH
			,uT4
			,uT3
			,uAlbumina
			,uFAL
			,uAmilasa
			,uCD4
			,uCD8
			,uOwner
			,uCreatedBy
		);

	macro_mySQLQueryHTMLError;

}//void Insert_tSangre(void)


void Update_tSangre(char *cRowid)
{
	sprintf(gcQuery,"UPDATE tSangre SET "
		"cLabel='%s',"
		"cLaboratorio='%s',"
		"cOtro='%s',"
		"uLDH=%u,"
		"uUrea=%u,"
		"uHb=%u,"
		"uHematocrito=%u,"
		"uLeucocitos=%u,"
		"uNeutrofilos=%u,"
		"uBasofilos=%u,"
		"uEosinofilos=%u,"
		"uLinfocitos=%u,"
		"uMonocitos=%u,"
		"uGlobulosRojos=%u,"
		"uPlaquetas=%u,"
		"uCreatinina=%u,"
		"uGlucemia=%u,"
		"uPCR=%u,"
		"uVSG=%u,"
		"uTGO=%u,"
		"uTGP=%u,"
		"uGGT=%u,"
		"uBilT=%u,"
		"uBilD=%u,"
		"uCPK=%u,"
		"uSodio=%u,"
		"uPotasio=%u,"
		"uCloro=%u,"
		"uTSH=%u,"
		"uT4=%u,"
		"uT3=%u,"
		"uAlbumina=%u,"
		"uFAL=%u,"
		"uAmilasa=%u,"
		"uCD4=%u,"
		"uCD8=%u,"
		"uOwner=%u,"
		"uModBy=%u,"
		"uModDate=UNIX_TIMESTAMP(NOW())"
		" WHERE _rowid=%s"
			,TextAreaSave(cLabel)
			,TextAreaSave(cLaboratorio)
			,TextAreaSave(cOtro)
			,uLDH
			,uUrea
			,uHb
			,uHematocrito
			,uLeucocitos
			,uNeutrofilos
			,uBasofilos
			,uEosinofilos
			,uLinfocitos
			,uMonocitos
			,uGlobulosRojos
			,uPlaquetas
			,uCreatinina
			,uGlucemia
			,uPCR
			,uVSG
			,uTGO
			,uTGP
			,uGGT
			,uBilT
			,uBilD
			,uCPK
			,uSodio
			,uPotasio
			,uCloro
			,uTSH
			,uT4
			,uT3
			,uAlbumina
			,uFAL
			,uAmilasa
			,uCD4
			,uCD8
			,uOwner
			,uModBy
			,cRowid
		);

	macro_mySQLQueryHTMLError;

}//void Update_tSangre(void)


void ModtSangre(void)
{
	register int i=0;
	MYSQL_RES *res;
	MYSQL_ROW field;
	unsigned uPreModDate=0;

	//Mod select gcQuery
	if(guPermLevel<10)
	sprintf(gcQuery,"SELECT tSangre.uSangre,"
				" tSangre.uModDate"
				" FROM tSangre,tClient"
				" WHERE tSangre.uSangre=%u"
				" AND tSangre.uOwner=tClient.uClient"
				" AND (tClient.uOwner=%u OR tClient.uClient=%u)"
					,uSangre,guLoginClient,guLoginClient);
	else
	sprintf(gcQuery,"SELECT uSangre,uModDate FROM tSangre"
				" WHERE uSangre=%u"
					,uSangre);

	macro_mySQLRunAndStore(res);
	i=mysql_num_rows(res);

	if(i<1) tSangre(LANG_NBR_RECNOTEXIST);
	if(i>1) tSangre(LANG_NBR_MULTRECS);

	field=mysql_fetch_row(res);
	sscanf(field[1],"%u",&uPreModDate);
	if(uPreModDate!=uModDate) tSangre(LANG_NBR_EXTMOD);

	Update_tSangre(field[0]);
	sprintf(gcQuery,LANG_NBRF_REC_MODIFIED,field[0]);
	uModDate=luGetModDate("tSangre",uSangre);
	unxsSaludLog(uSangre,"tSangre","Mod");
	tSangre(gcQuery);

}//ModtSangre(void)


void tSangreList(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;

	ExttSangreListSelect();

	macro_mySQLRunAndStore(res);
	guI=mysql_num_rows(res);

	PageMachine("tSangreList",1,"");//1 is auto header list guMode. Opens table!

	//Filter select drop down
	ExttSangreListFilter();

	printf("<input type=text size=16 name=gcCommand maxlength=98 value=\"%s\" >",gcCommand);

	printf("</table>\n");

	printf("<table bgcolor=#9BC1B3 border=0 width=100%%>\n");
	printf("<tr bgcolor=black>"
		"<td><font face=arial,helvetica color=white>uSangre"
		"<td><font face=arial,helvetica color=white>cLabel"
		"<td><font face=arial,helvetica color=white>cLaboratorio"
		"<td><font face=arial,helvetica color=white>cOtro"
		"<td><font face=arial,helvetica color=white>uLDH"
		"<td><font face=arial,helvetica color=white>uUrea"
		"<td><font face=arial,helvetica color=white>uHb"
		"<td><font face=arial,helvetica color=white>uHematocrito"
		"<td><font face=arial,helvetica color=white>uLeucocitos"
		"<td><font face=arial,helvetica color=white>uNeutrofilos"
		"<td><font face=arial,helvetica color=white>uBasofilos"
		"<td><font face=arial,helvetica color=white>uEosinofilos"
		"<td><font face=arial,helvetica color=white>uLinfocitos"
		"<td><font face=arial,helvetica color=white>uMonocitos"
		"<td><font face=arial,helvetica color=white>uGlobulosRojos"
		"<td><font face=arial,helvetica color=white>uPlaquetas"
		"<td><font face=arial,helvetica color=white>uCreatinina"
		"<td><font face=arial,helvetica color=white>uGlucemia"
		"<td><font face=arial,helvetica color=white>uPCR"
		"<td><font face=arial,helvetica color=white>uVSG"
		"<td><font face=arial,helvetica color=white>uTGO"
		"<td><font face=arial,helvetica color=white>uTGP"
		"<td><font face=arial,helvetica color=white>uGGT"
		"<td><font face=arial,helvetica color=white>uBilT"
		"<td><font face=arial,helvetica color=white>uBilD"
		"<td><font face=arial,helvetica color=white>uCPK"
		"<td><font face=arial,helvetica color=white>uSodio"
		"<td><font face=arial,helvetica color=white>uPotasio"
		"<td><font face=arial,helvetica color=white>uCloro"
		"<td><font face=arial,helvetica color=white>uTSH"
		"<td><font face=arial,helvetica color=white>uT4"
		"<td><font face=arial,helvetica color=white>uT3"
		"<td><font face=arial,helvetica color=white>uAlbumina"
		"<td><font face=arial,helvetica color=white>uFAL"
		"<td><font face=arial,helvetica color=white>uAmilasa"
		"<td><font face=arial,helvetica color=white>uCD4"
		"<td><font face=arial,helvetica color=white>uCD8"
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
				char cBuf37[128];
		sprintf(cBuf37,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[37],
			ForeignKey("tClient","cLabel",strtoul(field[37],NULL,10)));
		char cBuf38[128];
		sprintf(cBuf38,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[38],
			ForeignKey("tClient","cLabel",strtoul(field[38],NULL,10)));
		time_t luTime39=strtoul(field[39],NULL,10);
		char cBuf39[32];
		if(luTime39)
			ctime_r(&luTime39,cBuf39);
		else
			sprintf(cBuf39,"---");
		char cBuf40[128];
		sprintf(cBuf40,"<a class=darkLink href=?gcFunction=tClient&uClient=%.32s>%.32s</a>",
			field[40],
			ForeignKey("tClient","cLabel",strtoul(field[40],NULL,10)));
		time_t luTime41=strtoul(field[41],NULL,10);
		char cBuf41[32];
		if(luTime41)
			ctime_r(&luTime41,cBuf41);
		else
			sprintf(cBuf41,"---");
		printf("<td><a class=darkLink href=unxsSalud.cgi?gcFunction=tSangre&uSangre=%s>%s</a><td>%s<td>%s<td><textarea disabled>%s</textarea><td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s<td>%s</tr>"
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
			,field[17]
			,field[18]
			,field[19]
			,field[20]
			,field[21]
			,field[22]
			,field[23]
			,field[24]
			,field[25]
			,field[26]
			,field[27]
			,field[28]
			,field[29]
			,field[30]
			,field[31]
			,field[32]
			,field[33]
			,field[34]
			,field[35]
			,field[36]
			,cBuf37
			,cBuf38
			,cBuf39
			,cBuf40
			,cBuf41
				);

	}

	printf("</table></form>\n");
	FooterRAD4();

}//tSangreList()


void CreatetSangre(void)
{
	sprintf(gcQuery,"CREATE TABLE IF NOT EXISTS tSangre ("
		"uSangre INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,"
		"cLabel VARCHAR(32) NOT NULL DEFAULT '',"
		"cLaboratorio VARCHAR(64) NOT NULL DEFAULT '',"
		"cOtro TEXT NOT NULL DEFAULT '',"
		"uLDH INT UNSIGNED NOT NULL DEFAULT 0,"
		"uUrea INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHb INT UNSIGNED NOT NULL DEFAULT 0,"
		"uHematocrito INT UNSIGNED NOT NULL DEFAULT 0,"
		"uLeucocitos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uNeutrofilos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uBasofilos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uEosinofilos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uLinfocitos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uMonocitos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uGlobulosRojos INT UNSIGNED NOT NULL DEFAULT 0,"
		"uPlaquetas INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatinina INT UNSIGNED NOT NULL DEFAULT 0,"
		"uGlucemia INT UNSIGNED NOT NULL DEFAULT 0,"
		"uPCR INT UNSIGNED NOT NULL DEFAULT 0,"
		"uVSG INT UNSIGNED NOT NULL DEFAULT 0,"
		"uTGO INT UNSIGNED NOT NULL DEFAULT 0,"
		"uTGP INT UNSIGNED NOT NULL DEFAULT 0,"
		"uGGT INT UNSIGNED NOT NULL DEFAULT 0,"
		"uBilT INT UNSIGNED NOT NULL DEFAULT 0,"
		"uBilD INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCPK INT UNSIGNED NOT NULL DEFAULT 0,"
		"uSodio INT UNSIGNED NOT NULL DEFAULT 0,"
		"uPotasio INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCloro INT UNSIGNED NOT NULL DEFAULT 0,"
		"uTSH INT UNSIGNED NOT NULL DEFAULT 0,"
		"uT4 INT UNSIGNED NOT NULL DEFAULT 0,"
		"uT3 INT UNSIGNED NOT NULL DEFAULT 0,"
		"uAlbumina INT UNSIGNED NOT NULL DEFAULT 0,"
		"uFAL INT UNSIGNED NOT NULL DEFAULT 0,"
		"uAmilasa INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCD4 INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCD8 INT UNSIGNED NOT NULL DEFAULT 0,"
		"uOwner INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uCreatedDate INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModBy INT UNSIGNED NOT NULL DEFAULT 0,"
		"uModDate INT UNSIGNED NOT NULL DEFAULT 0 )");
	mysql_query(&gMysql,gcQuery);
	if(mysql_errno(&gMysql))
		htmlPlainTextError(mysql_error(&gMysql));
}//void CreatetSangre(void)



