/*
FILE
	$Id: mysqlrad.h 2085 2012-09-06 03:27:21Z Dylan $
AUTHOR
	(C) 2001-2008 Gary Wallis and Hugo Urquiza. 
	(C) 2009-2012 Gary Wallis for Unixservice LLC.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
//This is an example tune for your system
#ifndef Linux
        #include <sys/systeminfo.h>
#else
        #ifndef FreeBSD
                #include <crypt.h>
        #endif
#endif
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/file.h>

#include "cgi.h"

//This is an example tune for your system
#ifdef FreeBSD
	#include "/usr/local/include/mysql/mysql.h"
#else
	#include <mysql/mysql.h>
#endif


#include <unistd.h>
#include <locale.h>
#include <monetary.h>

#include "language.h"
#include "local.h"

 //Native MySQL fields
#define COLTYPE_DECIMAL 0
#define COLTYPE_MONEY 1102 //For BCD in future. Now allows $250,000.00 style input and output.
#define COLTYPE_INTUNSIGNED 3
#define COLTYPE_TIMESTAMP 7
#define COLTYPE_DATETIME 12
#define COLTYPE_CHAR 254
#define COLTYPE_VARCHAR 253
#define COLTYPE_TEXT 252
#define COLTYPE_IMAGE 1101
#define COLTYPE_FKIMAGE 1200
#define COLTYPE_BIGINT 8

 //Our special gui fields
#define COLTYPE_SELECTTABLE 1000
#define COLTYPE_SELECTTABLE_OWNER 1100
#define COLTYPE_RADPRI 1001
#define COLTYPE_PRIKEY 1002
#define COLTYPE_YESNO 1003
#define COLTYPE_UNIXTIMECREATE 1004
#define COLTYPE_UNIXTIMEUPDATE 1005
#define COLTYPE_EXTFUNC 1006
#define COLTYPE_FOREIGNKEY 1007
#define COLTYPE_UINTUKEY 1008
#define COLTYPE_VARCHARUKEY 1009
#define COLTYPE_UNIXTIME 2000

extern char gcHost[];
extern char gcHostname[];
extern char gcUser[];
#define PERMLEVEL
extern int guPermLevel; 
extern unsigned guLoginClient; 
extern unsigned guReseller; 
extern unsigned guCompany; 
extern unsigned guCookieProject,guCookieTable,guCookieField;
void SetSessionCookie(void);

extern char gcFunction[];
extern unsigned guListMode; 
extern char gcQuery[];
extern char *gcQstr;
extern char *gcRADStatus;
extern MYSQL gMysql; 
extern MYSQL gMysql2; 
extern unsigned long gluRowid;
extern unsigned guStart;
extern unsigned guEnd;
extern unsigned guI;
extern unsigned guN;
extern char gcCommand[];
extern char gcFilter[];
extern char gcFind[];
extern char gcTable[];
extern unsigned guMode;
extern int guError;
extern char gcErrormsg[];

void unxsSalud(const char *cResult);
void ConnectDb(void);
void FooterRAD4(void);
void HeaderRAD4(char *cMsg, int iJs);
void ProcessControlVars(pentry entries[], int x);
void OpenRow(const char *cFieldLabel, const char *cColor);
void OpenFieldSet(char *cLabel, unsigned uWidth);
void CloseFieldSet(void);
void LoadConf(void);
void NoSuchFunction(void);
void tTablePullDown(const char *cTableName, const char *cFieldName,
                        const char *cOrderby, unsigned uSelector, unsigned uMode);
void tTablePullDownOwner(const char *cTableName, const char *cFieldName,
                        const char *cOrderby, unsigned uSelector, unsigned uMode);
void tTablePullDownReadOnly(const char *cTableName, const char *cFieldName,
                        const char *cOrderby, unsigned uSelector);
int ReadPullDown(const char *cTableName,const char *cFieldName,const char *cLabel);
int ReadPullDownOwner(const char *cTableName,const char *cFieldName,
				const char *cLabel,const unsigned uOwner);
char *TextAreaSave(char *cField);
char *TransformAngleBrackets(char *cField);
char *EncodeDoubleQuotes(char *cField);
void YesNoPullDown(char *cFieldName,unsigned uSelect,unsigned uMode);
void YesNo(unsigned uSelect);
int ReadYesNoPullDown(const char *cLabel);
const char *ForeignKey(const char *cTableName, const char *cFieldName, unsigned uKey);
void GetClientOwner(unsigned uClient, unsigned *uOwner);
void ExtMainShell(int argc, char *argv[]);
void jsCalendarInput(char *cInputName,char *cValue,unsigned uMode);
long unsigned luGetModDate(char *cTableName, unsigned uTablePK);
long unsigned luGetCreatedDate(char *cTableName, unsigned uTablePK);
void DashBoard(const char *cOptionalMsg);
void htmlPlainTextError(const char *cError);
void TextError(const char *cError, unsigned uContinue);
unsigned uAllowMod(const unsigned uOwner, const unsigned uCreatedBy);
unsigned uAllowDel(const unsigned uOwner, const unsigned uCreatedBy);
void ExtSelect(const char *cTable,const char *cVarList,unsigned uMaxResults);
void ExtSelectSearch(const char *cTable,const char *cVarList,const char *cSearchField,const char *cSearch);
void ExtSelectRow(const char *cTable,const char *cVarList,unsigned uRow);
void ExtListSelect(const char *cTable,const char *cVarList);

void unxsSaludLog(unsigned uTablePK, char *cTableName, char *cLogEntry);
void GetConfiguration(const char *cName,char *cValue,unsigned uValueSize, unsigned uServer, unsigned uHtml);
void EncryptPasswdWithSalt(char *cPasswd,char *cSalt);
void EncryptPasswd(char *cPasswd);

 //Standard tInputFunc functions
char *WordToLower(char *cInput);
char *IPNumber(char *cInput);
char *IPv4All(char *cInput);
char *IPv4Range(char *cInput);
char *IPv4CIDR(char *cInput);
char *FQDomainName(char *cInput);
char *EmailInput(char *cInput);
char *cMoneyInput(char *cInput);
char *cMoneyDisplay(char *cInput);

 //Standard tValidFunc functions
const char *EmptyString(const char *cInput);
const char *BadIPNum(const char *cInput);
const char *IsZero(const unsigned uInput);

 //External pagination form processing vars
void PageMachine(char *cFuncName, int iLmode, char *cMsg);

 //Place ModuleCommands() and Module() prototypes here
#define ISPNAME "OpenISP"
#define ISPURL "www.openisp.net"
#define ADMIN 9

//tPaciente
int tPacienteCommands(pentry entries[], int x);
void tPaciente(const char *results);
void ProcesstPacienteVars(pentry entries[], int x);
void tPacienteContent(void);
void tPacienteInputContent(void);
void tPacienteInput(unsigned uMode);
void tPacienteList(void);
void NewtPaciente(unsigned uMode);
void ModtPaciente(void);
void CreatetPaciente(void);
void DeletetPaciente(void);
void ExttPacienteGetHook(entry gentries[], int x);
void ExttPacienteNavBar(void);

//tConsulta
int tConsultaCommands(pentry entries[], int x);
void tConsulta(const char *results);
void ProcesstConsultaVars(pentry entries[], int x);
void tConsultaContent(void);
void tConsultaInputContent(void);
void tConsultaInput(unsigned uMode);
void tConsultaList(void);
void NewtConsulta(unsigned uMode);
void ModtConsulta(void);
void CreatetConsulta(void);
void DeletetConsulta(void);
void ExttConsultaGetHook(entry gentries[], int x);
void ExttConsultaNavBar(void);

//tMotivo
int tMotivoCommands(pentry entries[], int x);
void tMotivo(const char *results);
void ProcesstMotivoVars(pentry entries[], int x);
void tMotivoContent(void);
void tMotivoInputContent(void);
void tMotivoInput(unsigned uMode);
void tMotivoList(void);
void NewtMotivo(unsigned uMode);
void ModtMotivo(void);
void CreatetMotivo(void);
void DeletetMotivo(void);
void ExttMotivoGetHook(entry gentries[], int x);
void ExttMotivoNavBar(void);

//tCentro
int tCentroCommands(pentry entries[], int x);
void tCentro(const char *results);
void ProcesstCentroVars(pentry entries[], int x);
void tCentroContent(void);
void tCentroInputContent(void);
void tCentroInput(unsigned uMode);
void tCentroList(void);
void NewtCentro(unsigned uMode);
void ModtCentro(void);
void CreatetCentro(void);
void DeletetCentro(void);
void ExttCentroGetHook(entry gentries[], int x);
void ExttCentroNavBar(void);

//tAntecedente
int tAntecedenteCommands(pentry entries[], int x);
void tAntecedente(const char *results);
void ProcesstAntecedenteVars(pentry entries[], int x);
void tAntecedenteContent(void);
void tAntecedenteInputContent(void);
void tAntecedenteInput(unsigned uMode);
void tAntecedenteList(void);
void NewtAntecedente(unsigned uMode);
void ModtAntecedente(void);
void CreatetAntecedente(void);
void DeletetAntecedente(void);
void ExttAntecedenteGetHook(entry gentries[], int x);
void ExttAntecedenteNavBar(void);

//tInternacion
int tInternacionCommands(pentry entries[], int x);
void tInternacion(const char *results);
void ProcesstInternacionVars(pentry entries[], int x);
void tInternacionContent(void);
void tInternacionInputContent(void);
void tInternacionInput(unsigned uMode);
void tInternacionList(void);
void NewtInternacion(unsigned uMode);
void ModtInternacion(void);
void CreatetInternacion(void);
void DeletetInternacion(void);
void ExttInternacionGetHook(entry gentries[], int x);
void ExttInternacionNavBar(void);

//tMedico
int tMedicoCommands(pentry entries[], int x);
void tMedico(const char *results);
void ProcesstMedicoVars(pentry entries[], int x);
void tMedicoContent(void);
void tMedicoInputContent(void);
void tMedicoInput(unsigned uMode);
void tMedicoList(void);
void NewtMedico(unsigned uMode);
void ModtMedico(void);
void CreatetMedico(void);
void DeletetMedico(void);
void ExttMedicoGetHook(entry gentries[], int x);
void ExttMedicoNavBar(void);

//tMedicacion
int tMedicacionCommands(pentry entries[], int x);
void tMedicacion(const char *results);
void ProcesstMedicacionVars(pentry entries[], int x);
void tMedicacionContent(void);
void tMedicacionInputContent(void);
void tMedicacionInput(unsigned uMode);
void tMedicacionList(void);
void NewtMedicacion(unsigned uMode);
void ModtMedicacion(void);
void CreatetMedicacion(void);
void DeletetMedicacion(void);
void ExttMedicacionGetHook(entry gentries[], int x);
void ExttMedicacionNavBar(void);

//tInmunizacion
int tInmunizacionCommands(pentry entries[], int x);
void tInmunizacion(const char *results);
void ProcesstInmunizacionVars(pentry entries[], int x);
void tInmunizacionContent(void);
void tInmunizacionInputContent(void);
void tInmunizacionInput(unsigned uMode);
void tInmunizacionList(void);
void NewtInmunizacion(unsigned uMode);
void ModtInmunizacion(void);
void CreatetInmunizacion(void);
void DeletetInmunizacion(void);
void ExttInmunizacionGetHook(entry gentries[], int x);
void ExttInmunizacionNavBar(void);

//tTipoConsulta
int tTipoConsultaCommands(pentry entries[], int x);
void tTipoConsulta(const char *results);
void ProcesstTipoConsultaVars(pentry entries[], int x);
void tTipoConsultaContent(void);
void tTipoConsultaInputContent(void);
void tTipoConsultaInput(unsigned uMode);
void tTipoConsultaList(void);
void NewtTipoConsulta(unsigned uMode);
void ModtTipoConsulta(void);
void CreatetTipoConsulta(void);
void DeletetTipoConsulta(void);
void ExttTipoConsultaGetHook(entry gentries[], int x);
void ExttTipoConsultaNavBar(void);

//tLaboratorio
int tLaboratorioCommands(pentry entries[], int x);
void tLaboratorio(const char *results);
void ProcesstLaboratorioVars(pentry entries[], int x);
void tLaboratorioContent(void);
void tLaboratorioInputContent(void);
void tLaboratorioInput(unsigned uMode);
void tLaboratorioList(void);
void NewtLaboratorio(unsigned uMode);
void ModtLaboratorio(void);
void CreatetLaboratorio(void);
void DeletetLaboratorio(void);
void ExttLaboratorioGetHook(entry gentries[], int x);
void ExttLaboratorioNavBar(void);

//tSangre
int tSangreCommands(pentry entries[], int x);
void tSangre(const char *results);
void ProcesstSangreVars(pentry entries[], int x);
void tSangreContent(void);
void tSangreInputContent(void);
void tSangreInput(unsigned uMode);
void tSangreList(void);
void NewtSangre(unsigned uMode);
void ModtSangre(void);
void CreatetSangre(void);
void DeletetSangre(void);
void ExttSangreGetHook(entry gentries[], int x);
void ExttSangreNavBar(void);

//tSerologia
int tSerologiaCommands(pentry entries[], int x);
void tSerologia(const char *results);
void ProcesstSerologiaVars(pentry entries[], int x);
void tSerologiaContent(void);
void tSerologiaInputContent(void);
void tSerologiaInput(unsigned uMode);
void tSerologiaList(void);
void NewtSerologia(unsigned uMode);
void ModtSerologia(void);
void CreatetSerologia(void);
void DeletetSerologia(void);
void ExttSerologiaGetHook(entry gentries[], int x);
void ExttSerologiaNavBar(void);

//tMicrobiologia
int tMicrobiologiaCommands(pentry entries[], int x);
void tMicrobiologia(const char *results);
void ProcesstMicrobiologiaVars(pentry entries[], int x);
void tMicrobiologiaContent(void);
void tMicrobiologiaInputContent(void);
void tMicrobiologiaInput(unsigned uMode);
void tMicrobiologiaList(void);
void NewtMicrobiologia(unsigned uMode);
void ModtMicrobiologia(void);
void CreatetMicrobiologia(void);
void DeletetMicrobiologia(void);
void ExttMicrobiologiaGetHook(entry gentries[], int x);
void ExttMicrobiologiaNavBar(void);

//tHemocultivo
int tHemocultivoCommands(pentry entries[], int x);
void tHemocultivo(const char *results);
void ProcesstHemocultivoVars(pentry entries[], int x);
void tHemocultivoContent(void);
void tHemocultivoInputContent(void);
void tHemocultivoInput(unsigned uMode);
void tHemocultivoList(void);
void NewtHemocultivo(unsigned uMode);
void ModtHemocultivo(void);
void CreatetHemocultivo(void);
void DeletetHemocultivo(void);
void ExttHemocultivoGetHook(entry gentries[], int x);
void ExttHemocultivoNavBar(void);

//tUrocultivo
int tUrocultivoCommands(pentry entries[], int x);
void tUrocultivo(const char *results);
void ProcesstUrocultivoVars(pentry entries[], int x);
void tUrocultivoContent(void);
void tUrocultivoInputContent(void);
void tUrocultivoInput(unsigned uMode);
void tUrocultivoList(void);
void NewtUrocultivo(unsigned uMode);
void ModtUrocultivo(void);
void CreatetUrocultivo(void);
void DeletetUrocultivo(void);
void ExttUrocultivoGetHook(entry gentries[], int x);
void ExttUrocultivoNavBar(void);

//tCultivoCateter
int tCultivoCateterCommands(pentry entries[], int x);
void tCultivoCateter(const char *results);
void ProcesstCultivoCateterVars(pentry entries[], int x);
void tCultivoCateterContent(void);
void tCultivoCateterInputContent(void);
void tCultivoCateterInput(unsigned uMode);
void tCultivoCateterList(void);
void NewtCultivoCateter(unsigned uMode);
void ModtCultivoCateter(void);
void CreatetCultivoCateter(void);
void DeletetCultivoCateter(void);
void ExttCultivoCateterGetHook(entry gentries[], int x);
void ExttCultivoCateterNavBar(void);

//tCultivoPB
int tCultivoPBCommands(pentry entries[], int x);
void tCultivoPB(const char *results);
void ProcesstCultivoPBVars(pentry entries[], int x);
void tCultivoPBContent(void);
void tCultivoPBInputContent(void);
void tCultivoPBInput(unsigned uMode);
void tCultivoPBList(void);
void NewtCultivoPB(unsigned uMode);
void ModtCultivoPB(void);
void CreatetCultivoPB(void);
void DeletetCultivoPB(void);
void ExttCultivoPBGetHook(entry gentries[], int x);
void ExttCultivoPBNavBar(void);

//tCultivoHueso
int tCultivoHuesoCommands(pentry entries[], int x);
void tCultivoHueso(const char *results);
void ProcesstCultivoHuesoVars(pentry entries[], int x);
void tCultivoHuesoContent(void);
void tCultivoHuesoInputContent(void);
void tCultivoHuesoInput(unsigned uMode);
void tCultivoHuesoList(void);
void NewtCultivoHueso(unsigned uMode);
void ModtCultivoHueso(void);
void CreatetCultivoHueso(void);
void DeletetCultivoHueso(void);
void ExttCultivoHuesoGetHook(entry gentries[], int x);
void ExttCultivoHuesoNavBar(void);

//tCultivoEsputo
int tCultivoEsputoCommands(pentry entries[], int x);
void tCultivoEsputo(const char *results);
void ProcesstCultivoEsputoVars(pentry entries[], int x);
void tCultivoEsputoContent(void);
void tCultivoEsputoInputContent(void);
void tCultivoEsputoInput(unsigned uMode);
void tCultivoEsputoList(void);
void NewtCultivoEsputo(unsigned uMode);
void ModtCultivoEsputo(void);
void CreatetCultivoEsputo(void);
void DeletetCultivoEsputo(void);
void ExttCultivoEsputoGetHook(entry gentries[], int x);
void ExttCultivoEsputoNavBar(void);

//tCultivoLCR
int tCultivoLCRCommands(pentry entries[], int x);
void tCultivoLCR(const char *results);
void ProcesstCultivoLCRVars(pentry entries[], int x);
void tCultivoLCRContent(void);
void tCultivoLCRInputContent(void);
void tCultivoLCRInput(unsigned uMode);
void tCultivoLCRList(void);
void NewtCultivoLCR(unsigned uMode);
void ModtCultivoLCR(void);
void CreatetCultivoLCR(void);
void DeletetCultivoLCR(void);
void ExttCultivoLCRGetHook(entry gentries[], int x);
void ExttCultivoLCRNavBar(void);

//tOrina
int tOrinaCommands(pentry entries[], int x);
void tOrina(const char *results);
void ProcesstOrinaVars(pentry entries[], int x);
void tOrinaContent(void);
void tOrinaInputContent(void);
void tOrinaInput(unsigned uMode);
void tOrinaList(void);
void NewtOrina(unsigned uMode);
void ModtOrina(void);
void CreatetOrina(void);
void DeletetOrina(void);
void ExttOrinaGetHook(entry gentries[], int x);
void ExttOrinaNavBar(void);

//tVirologia
int tVirologiaCommands(pentry entries[], int x);
void tVirologia(const char *results);
void ProcesstVirologiaVars(pentry entries[], int x);
void tVirologiaContent(void);
void tVirologiaInputContent(void);
void tVirologiaInput(unsigned uMode);
void tVirologiaList(void);
void NewtVirologia(unsigned uMode);
void ModtVirologia(void);
void CreatetVirologia(void);
void DeletetVirologia(void);
void ExttVirologiaGetHook(entry gentries[], int x);
void ExttVirologiaNavBar(void);

//tVitales
int tVitalesCommands(pentry entries[], int x);
void tVitales(const char *results);
void ProcesstVitalesVars(pentry entries[], int x);
void tVitalesContent(void);
void tVitalesInputContent(void);
void tVitalesInput(unsigned uMode);
void tVitalesList(void);
void NewtVitales(unsigned uMode);
void ModtVitales(void);
void CreatetVitales(void);
void DeletetVitales(void);
void ExttVitalesGetHook(entry gentries[], int x);
void ExttVitalesNavBar(void);

//tClient
int tClientCommands(pentry entries[], int x);
void tClient(const char *results);
void ProcesstClientVars(pentry entries[], int x);
void tClientContent(void);
void tClientInputContent(void);
void tClientInput(unsigned uMode);
void tClientList(void);
void NewtClient(unsigned uMode);
void ModtClient(void);
void CreatetClient(void);
void DeletetClient(void);
void ExttClientGetHook(entry gentries[], int x);
void ExttClientNavBar(void);

//tAuthorize
int tAuthorizeCommands(pentry entries[], int x);
void tAuthorize(const char *results);
void ProcesstAuthorizeVars(pentry entries[], int x);
void tAuthorizeContent(void);
void tAuthorizeInputContent(void);
void tAuthorizeInput(unsigned uMode);
void tAuthorizeList(void);
void NewtAuthorize(unsigned uMode);
void ModtAuthorize(void);
void CreatetAuthorize(void);
void DeletetAuthorize(void);
void ExttAuthorizeGetHook(entry gentries[], int x);
void ExttAuthorizeNavBar(void);

//tServer
int tServerCommands(pentry entries[], int x);
void tServer(const char *results);
void ProcesstServerVars(pentry entries[], int x);
void tServerContent(void);
void tServerInputContent(void);
void tServerInput(unsigned uMode);
void tServerList(void);
void NewtServer(unsigned uMode);
void ModtServer(void);
void CreatetServer(void);
void DeletetServer(void);
void ExttServerGetHook(entry gentries[], int x);
void ExttServerNavBar(void);

//tConfiguration
int tConfigurationCommands(pentry entries[], int x);
void tConfiguration(const char *results);
void ProcesstConfigurationVars(pentry entries[], int x);
void tConfigurationContent(void);
void tConfigurationInputContent(void);
void tConfigurationInput(unsigned uMode);
void tConfigurationList(void);
void NewtConfiguration(unsigned uMode);
void ModtConfiguration(void);
void CreatetConfiguration(void);
void DeletetConfiguration(void);
void ExttConfigurationGetHook(entry gentries[], int x);
void ExttConfigurationNavBar(void);

//tStatus
int tStatusCommands(pentry entries[], int x);
void tStatus(const char *results);
void ProcesstStatusVars(pentry entries[], int x);
void tStatusContent(void);
void tStatusInputContent(void);
void tStatusInput(unsigned uMode);
void tStatusList(void);
void NewtStatus(unsigned uMode);
void ModtStatus(void);
void CreatetStatus(void);
void DeletetStatus(void);
void ExttStatusGetHook(entry gentries[], int x);
void ExttStatusNavBar(void);

//tJobStatus
int tJobStatusCommands(pentry entries[], int x);
void tJobStatus(const char *results);
void ProcesstJobStatusVars(pentry entries[], int x);
void tJobStatusContent(void);
void tJobStatusInputContent(void);
void tJobStatusInput(unsigned uMode);
void tJobStatusList(void);
void NewtJobStatus(unsigned uMode);
void ModtJobStatus(void);
void CreatetJobStatus(void);
void DeletetJobStatus(void);
void ExttJobStatusGetHook(entry gentries[], int x);
void ExttJobStatusNavBar(void);

//tJob
int tJobCommands(pentry entries[], int x);
void tJob(const char *results);
void ProcesstJobVars(pentry entries[], int x);
void tJobContent(void);
void tJobInputContent(void);
void tJobInput(unsigned uMode);
void tJobList(void);
void NewtJob(unsigned uMode);
void ModtJob(void);
void CreatetJob(void);
void DeletetJob(void);
void ExttJobGetHook(entry gentries[], int x);
void ExttJobNavBar(void);

//tGlossary
int tGlossaryCommands(pentry entries[], int x);
void tGlossary(const char *results);
void ProcesstGlossaryVars(pentry entries[], int x);
void tGlossaryContent(void);
void tGlossaryInputContent(void);
void tGlossaryInput(unsigned uMode);
void tGlossaryList(void);
void NewtGlossary(unsigned uMode);
void ModtGlossary(void);
void CreatetGlossary(void);
void DeletetGlossary(void);
void ExttGlossaryGetHook(entry gentries[], int x);
void ExttGlossaryNavBar(void);

//tTemplate
int tTemplateCommands(pentry entries[], int x);
void tTemplate(const char *results);
void ProcesstTemplateVars(pentry entries[], int x);
void tTemplateContent(void);
void tTemplateInputContent(void);
void tTemplateInput(unsigned uMode);
void tTemplateList(void);
void NewtTemplate(unsigned uMode);
void ModtTemplate(void);
void CreatetTemplate(void);
void DeletetTemplate(void);
void ExttTemplateGetHook(entry gentries[], int x);
void ExttTemplateNavBar(void);

//tTemplateSet
int tTemplateSetCommands(pentry entries[], int x);
void tTemplateSet(const char *results);
void ProcesstTemplateSetVars(pentry entries[], int x);
void tTemplateSetContent(void);
void tTemplateSetInputContent(void);
void tTemplateSetInput(unsigned uMode);
void tTemplateSetList(void);
void NewtTemplateSet(unsigned uMode);
void ModtTemplateSet(void);
void CreatetTemplateSet(void);
void DeletetTemplateSet(void);
void ExttTemplateSetGetHook(entry gentries[], int x);
void ExttTemplateSetNavBar(void);

//tTemplateType
int tTemplateTypeCommands(pentry entries[], int x);
void tTemplateType(const char *results);
void ProcesstTemplateTypeVars(pentry entries[], int x);
void tTemplateTypeContent(void);
void tTemplateTypeInputContent(void);
void tTemplateTypeInput(unsigned uMode);
void tTemplateTypeList(void);
void NewtTemplateType(unsigned uMode);
void ModtTemplateType(void);
void CreatetTemplateType(void);
void DeletetTemplateType(void);
void ExttTemplateTypeGetHook(entry gentries[], int x);
void ExttTemplateTypeNavBar(void);

//tLog
int tLogCommands(pentry entries[], int x);
void tLog(const char *results);
void ProcesstLogVars(pentry entries[], int x);
void tLogContent(void);
void tLogInputContent(void);
void tLogInput(unsigned uMode);
void tLogList(void);
void NewtLog(unsigned uMode);
void ModtLog(void);
void CreatetLog(void);
void DeletetLog(void);
void ExttLogGetHook(entry gentries[], int x);
void ExttLogNavBar(void);

//tLogType
int tLogTypeCommands(pentry entries[], int x);
void tLogType(const char *results);
void ProcesstLogTypeVars(pentry entries[], int x);
void tLogTypeContent(void);
void tLogTypeInputContent(void);
void tLogTypeInput(unsigned uMode);
void tLogTypeList(void);
void NewtLogType(unsigned uMode);
void ModtLogType(void);
void CreatetLogType(void);
void DeletetLogType(void);
void ExttLogTypeGetHook(entry gentries[], int x);
void ExttLogTypeNavBar(void);

//tLogMonth
int tLogMonthCommands(pentry entries[], int x);
void tLogMonth(const char *results);
void ProcesstLogMonthVars(pentry entries[], int x);
void tLogMonthContent(void);
void tLogMonthInputContent(void);
void tLogMonthInput(unsigned uMode);
void tLogMonthList(void);
void NewtLogMonth(unsigned uMode);
void ModtLogMonth(void);
void CreatetLogMonth(void);
void DeletetLogMonth(void);
void ExttLogMonthGetHook(entry gentries[], int x);
void ExttLogMonthNavBar(void);

//tMonth
int tMonthCommands(pentry entries[], int x);
void tMonth(const char *results);
void ProcesstMonthVars(pentry entries[], int x);
void tMonthContent(void);
void tMonthInputContent(void);
void tMonthInput(unsigned uMode);
void tMonthList(void);
void NewtMonth(unsigned uMode);
void ModtMonth(void);
void CreatetMonth(void);
void DeletetMonth(void);
void ExttMonthGetHook(entry gentries[], int x);
void ExttMonthNavBar(void);



//Standard RAD4 tables
//tTemplate
int tTemplateCommands(pentry entries[], int x);
void tTemplate(const char *results);
void ProcesstTemplateVars(pentry entries[], int x);
void tTemplateContent(void);
void tTemplateInputContent(void);
void tTemplateInput(unsigned uMode);
void tTemplateList(void);
void NewtTemplate(unsigned uMode);
void ModtTemplate(void);
void CreatetTemplate(void);
void DeletetTemplate(void);
void ExttTemplateGetHook(entry gentries[], int x);
void ExttTemplateNavBar(void);

//tTemplateSet
int tTemplateSetCommands(pentry entries[], int x);
void tTemplateSet(const char *results);
void ProcesstTemplateSetVars(pentry entries[], int x);
void tTemplateSetContent(void);
void tTemplateSetInputContent(void);
void tTemplateSetInput(unsigned uMode);
void tTemplateSetList(void);
void NewtTemplateSet(unsigned uMode);
void ModtTemplateSet(void);
void CreatetTemplateSet(void);
void DeletetTemplateSet(void);
void ExttTemplateSetGetHook(entry gentries[], int x);
void ExttTemplateSetNavBar(void);

//tTemplateType
int tTemplateTypeCommands(pentry entries[], int x);
void tTemplateType(const char *results);
void ProcesstTemplateTypeVars(pentry entries[], int x);
void tTemplateTypeContent(void);
void tTemplateTypeInputContent(void);
void tTemplateTypeInput(unsigned uMode);
void tTemplateTypeList(void);
void NewtTemplateType(unsigned uMode);
void ModtTemplateType(void);
void CreatetTemplateType(void);
void DeletetTemplateType(void);
void ExttTemplateTypeGetHook(entry gentries[], int x);
void ExttTemplateTypeNavBar(void);

//tClient
int tClientCommands(pentry entries[], int x);
void tClient(const char *results);
void ProcesstClientVars(pentry entries[], int x);
void tClientContent(void);
void tClientInputContent(void);
void tClientInput(unsigned uMode);
void tClientList(void);
void NewtClient(unsigned uMode);
void ModtClient(void);
void CreatetClient(void);
void DeletetClient(void);
void ExttClientGetHook(entry gentries[], int x);
void ExttClientNavBar(void);

//tAuthorize
int tAuthorizeCommands(pentry entries[], int x);
void tAuthorize(const char *results);
void ProcesstAuthorizeVars(pentry entries[], int x);
void tAuthorizeContent(void);
void tAuthorizeInputContent(void);
void tAuthorizeInput(unsigned uMode);
void tAuthorizeList(void);
void NewtAuthorize(unsigned uMode);
void ModtAuthorize(void);
void CreatetAuthorize(void);
void DeletetAuthorize(void);
void ExttAuthorizeGetHook(entry gentries[], int x);
void ExttAuthorizeNavBar(void);

//tStatus
int tStatusCommands(pentry entries[], int x);
void tStatus(const char *results);
void ProcesstStatusVars(pentry entries[], int x);
void tStatusContent(void);
void tStatusInputContent(void);
void tStatusInput(unsigned uMode);
void tStatusList(void);
void NewtStatus(unsigned uMode);
void ModtStatus(void);
void CreatetStatus(void);
void DeletetStatus(void);
void ExttStatusGetHook(entry gentries[], int x);
void ExttStatusNavBar(void);

//tLog
int tLogCommands(pentry entries[], int x);
void tLog(const char *results);
void ProcesstLogVars(pentry entries[], int x);
void tLogContent(void);
void tLogInputContent(void);
void tLogInput(unsigned uMode);
void tLogList(void);
void NewtLog(unsigned uMode);
void ModtLog(void);
void CreatetLog(void);
void DeletetLog(void);
void ExttLogGetHook(entry gentries[], int x);
void ExttLogNavBar(void);

//tLogType
int tLogTypeCommands(pentry entries[], int x);
void tLogType(const char *results);
void ProcesstLogTypeVars(pentry entries[], int x);
void tLogTypeContent(void);
void tLogTypeInputContent(void);
void tLogTypeInput(unsigned uMode);
void tLogTypeList(void);
void NewtLogType(unsigned uMode);
void ModtLogType(void);
void CreatetLogType(void);
void DeletetLogType(void);
void ExttLogTypeGetHook(entry gentries[], int x);
void ExttLogTypeNavBar(void);

//tLogMonth
int tLogMonthCommands(pentry entries[], int x);
void tLogMonth(const char *results);
void ProcesstLogMonthVars(pentry entries[], int x);
void tLogMonthContent(void);
void tLogMonthInputContent(void);
void tLogMonthInput(unsigned uMode);
void tLogMonthList(void);
void NewtLogMonth(unsigned uMode);
void ModtLogMonth(void);
void CreatetLogMonth(void);
void DeletetLogMonth(void);
void ExttLogMonthGetHook(entry gentries[], int x);
void ExttLogMonthNavBar(void);

//tGlossary
int tGlossaryCommands(pentry entries[], int x);
void tGlossary(const char *results);
void ProcesstGlossaryVars(pentry entries[], int x);
void tGlossaryContent(void);
void tGlossaryInputContent(void);
void tGlossaryInput(unsigned uMode);
void tGlossaryList(void);
void NewtGlossary(unsigned uMode);
void ModtGlossary(void);
void CreatetGlossary(void);
void DeletetGlossary(void);
void ExttGlossaryGetHook(entry gentries[], int x);
void ExttGlossaryNavBar(void);

//tJob
int tJobCommands(pentry entries[], int x);
void tJob(const char *results);
void ProcesstJobVars(pentry entries[], int x);
void tJobContent(void);
void tJobInputContent(void);
void tJobInput(unsigned uMode);
void tJobList(void);
void NewtJob(unsigned uMode);
void ModtJob(void);
void CreatetJob(void);
void DeletetJob(void);
void ExttJobGetHook(entry gentries[], int x);
void ExttJobNavBar(void);

//tJobStatus
int tJobStatusCommands(pentry entries[], int x);
void tJobStatus(const char *results);
void ProcesstJobStatusVars(pentry entries[], int x);
void tJobStatusContent(void);
void tJobStatusInputContent(void);
void tJobStatusInput(unsigned uMode);
void tJobStatusList(void);
void NewtJobStatus(unsigned uMode);
void ModtJobStatus(void);
void CreatetJobStatus(void);
void DeletetJobStatus(void);
void ExttJobStatusGetHook(entry gentries[], int x);
void ExttJobStatusNavBar(void);

//tMonth
int tMonthCommands(pentry entries[], int x);
void tMonth(const char *results);
void ProcesstMonthVars(pentry entries[], int x);
void tMonthContent(void);
void tMonthInputContent(void);
void tMonthInput(unsigned uMode);
void tMonthList(void);
void NewtMonth(unsigned uMode);
void ModtMonth(void);
void CreatetMonth(void);
void DeletetMonth(void);
void ExttMonthGetHook(entry gentries[], int x);
void ExttMonthNavBar(void);

//tConfiguration
int tConfigurationCommands(pentry entries[], int x);
void tConfiguration(const char *results);
void ProcesstConfigurationVars(pentry entries[], int x);
void tConfigurationContent(void);
void tConfigurationInputContent(void);
void tConfigurationInput(unsigned uMode);
void tConfigurationList(void);
void NewtConfiguration(unsigned uMode);
void ModtConfiguration(void);
void CreatetConfiguration(void);
void DeletetConfiguration(void);
void ExttConfigurationGetHook(entry gentries[], int x);
void ExttConfigurationNavBar(void);

//tServer
int tServerCommands(pentry entries[], int x);
void tServer(const char *results);
void ProcesstServerVars(pentry entries[], int x);
void tServerContent(void);
void tServerInputContent(void);
void tServerInput(unsigned uMode);
void tServerList(void);
void NewtServer(unsigned uMode);
void ModtServer(void);
void CreatetServer(void);
void DeletetServer(void);
void ExttServerGetHook(entry gentries[], int x);
void ExttServerNavBar(void);



//In-line code macros

//Comon - This macro shouldn't be used directly, as is part of the others only
#define macro_mySQLQueryBasic mysql_query(&gMysql,gcQuery);\
				if(mysql_errno(&gMysql))

//MySQL run query only w/error checking
//HTML
#define macro_mySQLQueryHTMLError macro_mySQLQueryBasic \
					htmlPlainTextError(mysql_error(&gMysql))
//Text
#define macro_mySQLQueryTextError macro_mySQLQueryBasic\
					{\
						fprintf(stderr,"%s\n",mysql_error(&gMysql));\
						exit(1);\
					}

//Text with return() instead of exit()
//return(1); if MySQL error
#define macro_mySQLRunReturnInt macro_mySQLQueryBasic\
				{\
					fprintf(stderr,"%s\n",mysql_error(&gMysql));\
					return(1);\
				}
//return void; if MySQL error
#define macro_mySQLRunReturnVoid macro_mySQLQueryBasic\
				{\
					fprintf(stderr,"%s\n",mysql_error(&gMysql));\
					return;\
				}

//MySQL run query and store result w/error checking
//HTML
#define macro_mySQLRunAndStore(res) macro_mySQLQueryHTMLError;\
					res=mysql_store_result(&gMysql)
//Text
#define macro_mySQLRunAndStoreText(res) macro_mySQLQueryBasic;\
					res=mysql_store_result(&gMysql)

//MySQL run query and store result w/error checking (Text); uses return() call instead of exit()
//return(1); if MySQL error
#define macro_mySQLRunAndStoreTextIntRet(res) macro_mySQLRunReturnInt;\
						res=mysql_store_result(&gMysql)
//return; if MySQL error
#define macro_mySQLRunAndStoreTextVoidRet(res) macro_mySQLRunReturnVoid;\
						res=mysql_store_result(&gMysql)

