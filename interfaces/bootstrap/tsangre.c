/*
FILE 
	tsangre.c
	Template unxsRAD/interfaces/bootstrap/table.c
AUTHOR/LEGAL
	(C) 2010-2017 Gary Wallis for Unixservice, LLC.
	GPLv2 license applies. See included LICENSE file.
PURPOSE
	For developing bootstrap/footable templates
	for unxsRAD RAD4 generated web apps.
*/

#include "interface.h"

//TOC
void ProcesstSangreVars(pentry entries[], int x);
void tSangreGetHook(entry gentries[],int x);
void tSangreCommands(pentry entries[], int x);
void htmltSangre(void);
void htmltSangrePage(char *cTitle, char *cTemplateName);
void jsontSangreRows(void);
void jsontSangreCols(void);

//funcModuleVars
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


void ProcesstSangreVars(pentry entries[], int x)
{
	register int i;
	
	char *cp;
	for(i=0;i<x;i++)
	{
		//no sql injection
		if((cp=strchr(entries[i].val,'\''))) *cp=0;

		//funcModuleProcVars
		
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

}//void ProcesstSangreVars(pentry entries[], int x)


void tSangreGetHook(entry gentries[],int x)
{
	//register int i;
	//for(i=0;i<x;i++)
	//{
	//}

	//API Get
	if(!strcmp(gcFunction,"SangreRows"))
		jsontSangreRows();
	else if(!strcmp(gcFunction,"SangreCols"))
		jsontSangreCols();
	htmltSangre();

}//void tSangreGetHook(entry gentries[],int x)


void tSangreCommands(pentry entries[], int x)
{
	if(!strcmp(gcPage,"Sangre"))
	{
		ProcesstSangreVars(entries,x);
		htmltSangre();
	}

	//API Post
        MYSQL_RES *res;
	MYSQL_ROW field;
	if(!strcmp(gcFunction,"SangreRows"))
		jsontSangreRows();
	else if(!strcmp(gcFunction,"SangreCols"))
		jsontSangreCols();
	else if(!strcmp(gcFunction,"AddSangre") || !strcmp(gcFunction,"ModSangre"))
	{
		ProcesstSangreVars(entries,x);
		printf("Content-type: text/plain\n\n");
		if(guPermLevel<7)
		{
			printf("insufficient permissions for add/mod\n");
			exit(0);
		}

		//Check data
		if(!cLabel[0])
		{
			printf("No cLabel for %u\n",uSangre);
			exit(0);
		}
		else
		{
			//Update or Insert
			if(!uSangre)
			{
				sprintf(gcQuery,"INSERT INTO tSangre"
					" SET cLabel='%s',uOwner=%u,uCreatedBy=%u,uCreatedDate=UNIX_TIMESTAMP(NOW())"
						,cLabel,guOrg,guLoginClient);
				mysql_query(&gMysql,gcQuery);
				if(mysql_errno(&gMysql))
				{
					printf("%s\n",mysql_error(&gMysql));
					exit(0);
				}
				printf("%llu\n",mysql_insert_id(&gMysql));
			}
			else
			{
				sprintf(gcQuery,"UPDATE tSangre SET cLabel='%s',uModBy=%u,uModDate=UNIX_TIMESTAMP(NOW())"
					" WHERE uSangre=%u"
						,cLabel,guLoginClient,uSangre);
				mysql_query(&gMysql,gcQuery);
				if(mysql_errno(&gMysql))
				{
					printf("%s\n",mysql_error(&gMysql));
					exit(0);
				}
				printf("%u\n",uSangre);
			}
		}
		exit(0);
	}
	else if(!strcmp(gcFunction,"DelSangre"))
	{
		ProcesstSangreVars(entries,x);

		printf("Content-type: text/plain\n\n");
		if(guPermLevel<10)
		{
			printf("insufficient permissions for delete\n");
			exit(0);
		}
		//check data
		if(uSangre)
		{
			sprintf(gcQuery,"SELECT uSangre FROM tSangre"
					" WHERE uSangre=%u"
					" AND (uCreatedBy=%u OR (uOwner=%u AND %u>=10))",
						uSangre,guLoginClient,guOrg,guPermLevel);
			mysql_query(&gMysql,gcQuery);
			if(mysql_errno(&gMysql))
			{
				printf("%s\n",mysql_error(&gMysql));
				exit(0);
			}
			res=mysql_store_result(&gMysql);
			if((field=mysql_fetch_row(res)))
			{
				sprintf(gcQuery,"DELETE FROM tSangre"
					" WHERE uSangre=%u"
					" AND (uCreatedBy=%u OR (uOwner=%u AND %u>=10))",
						uSangre,guLoginClient,guOrg,guPermLevel);
				mysql_query(&gMysql,gcQuery);
				if(mysql_errno(&gMysql))
				{
					printf("%s\n",mysql_error(&gMysql));
					exit(0);
				}
				if(mysql_affected_rows(&gMysql)>0)
					printf("%u\n",uSangre);
				else
					printf("Sangre not deleted. Unexpected mysql_affected_rows() error\n");
			}
			else
			{
				printf("Sangre not deleted. Insuficient permissions. guOrg=%u guPermLevel=%u\n",guOrg,guPermLevel);
			}
		}
		else
		{
			printf("Sangre not found %u\n",uSangre);
		}
		exit(0);
	}

}//void tSangreCommands(pentry entries[], int x)


void htmltSangre(void)
{
	htmlHeader("tSangre","Default.Header");
	htmltSangrePage("tSangre","Sangre.Body");
	htmlFooter("Default.Footer");

}//void htmltSangre(void)


void htmltSangrePage(char *cTitle, char *cTemplateName)
{
	if(cTemplateName[0])
	{
        	MYSQL_RES *res;
	        MYSQL_ROW field;

		TemplateSelectInterface(cTemplateName,uDEFAULT,uBOOTSTRAP);
		res=mysql_store_result(&gMysql);
		if((field=mysql_fetch_row(res)))
		{
			struct t_template template;

			template.cpName[0]="cTitle";
			template.cpValue[0]=cTitle;
			
			template.cpName[1]="cCGI";
			template.cpValue[1]="mobile.cgi";
			
			template.cpName[2]="gcLogin";
			template.cpValue[2]=gcUser;

			template.cpName[3]="gcName";
			template.cpValue[3]=gcName;

			template.cpName[4]="gcOrgName";
			template.cpValue[4]=gcOrgName;

			template.cpName[5]="cUserLevel";
			template.cpValue[5]=(char *)cUserLevel(guPermLevel);//Safe?

			template.cpName[6]="gcHost";
			template.cpValue[6]=gcHost;

			template.cpName[7]="gcMessage";
			template.cpValue[7]=gcMessage;

			template.cpName[8]="gcBrand";
			template.cpValue[8]=INTERFACE_HEADER_TITLE;

			template.cpName[9]="gcCopyright";
			template.cpValue[9]=INTERFACE_COPYRIGHT;

			template.cpName[10]="";

			printf("\n<!-- Start htmltSangrePage(%s) -->\n",cTemplateName); 
			Template(field[0],&template,stdout);
			printf("\n<!-- End htmltSangrePage(%s) -->\n",cTemplateName); 
		}
		else
		{
			printf("<hr>");
			printf("<center><font size=1>%s</font>\n",cTemplateName);
		}
		mysql_free_result(res);
	}

}//void htmltSangrePage()


void jsontSangreRows(void)
{
	MYSQL_RES *res;
	MYSQL_ROW field;
	char cQuery[1028]={""};

	printf("Content-type: text/json\n\n");
	printf("[\n");

	sprintf(cQuery,"SELECT tSangre.uSangre,tSangre.cLabel,tClient.cLabel"
			" FROM tSangre,tClient"
			" WHERE tSangre.uOwner=%u AND tClient.uClient=tSangre.uOwner",guOrg);
	mysql_query(&gMysql,cQuery);
	if(mysql_errno(&gMysql))
	{
		printf("\t{\n");
		printf("\t\t'status' : 'error',\n");
		printf("\t\t'message' : 'error: %s',\n",mysql_error(&gMysql));
		printf("\t}\n");
		printf("]\n");
		exit(0);
	}
	res=mysql_store_result(&gMysql);
	unsigned uNumRows=0;
	if((uNumRows=mysql_num_rows(res))>0)
	{
		unsigned uLast=0;
		while((field=mysql_fetch_row(res)))
		{
			printf("\t{");
			printf("\"uSangre\": \"%s\","
				" \"cLabel\": \"%s\","
				" \"cOwner\": \"%s\""
					,field[0],field[1],field[2]);
			printf("}");
			if((++uLast)<uNumRows)
				printf(",\n");
			else
				printf("\n");
		}
	}
	mysql_free_result(res);
	printf("]\n");
	exit(0);

}//void jsontSangreRows(void)


void jsontSangreCols(void)
{
	printf("Content-type: text/json\n\n");
	printf("[\n");
	//printf("\t{\"name\": \"uSangre\", \"title\": \"Unique Sangre ID\", \"filterable\": false },\n");
	printf("\t{\"name\": \"uSangre\", \"title\": \"Sangre ID\" },\n");
	printf("\t{\"name\": \"cLabel\", \"title\": \"Label\"},\n");
	printf("\t{\"name\": \"cOwner\", \"title\": \"Owner\", \"breakpoints\": \"xs sm\"}\n");
	printf("]\n");
	exit(0);
}//void jsontSangreCols(void)
