//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit_Shed.h"
#include "Unit_data.h"
#include "Unit_main.h"
#include "Unit_Pers.h"
#include "Unit_Calndr.h"
//#include "Unit_Client.h"
#include "Unit_About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Planner"
/*#pragma link "PlanSimpleEdit"
#pragma link "PlannerWaitList"
#pragma link "PlanItemEdit"
#pragma link "PlanRecurrEdit"
#pragma link "PlanPeriodEdit"  */
#pragma resource "*.dfm"
TForm_Shed *Form_Shed;
//---------------------------------------------------------------------------
__fastcall TForm_Shed::TForm_Shed(TComponent* Owner)
        : TForm(Owner)
{
shag=30;
du=30;
ServName="";
ItemIndex=0;
show_form=false;
}
//---------------------------------------------------------------------------







void __fastcall TForm_Shed::Planner1ItemStartEdit(TObject *Sender,
      TPlannerItem *Item)
{
 Item->ReadOnly =false;
  Item->Selected =false;
  Item->ShowSelection =false;

  Planner1->UpdateItem(Item);
}
//---------------------------------------------------------------------------




void __fastcall TForm_Shed::Planner1ItemEndEdit(TObject *Sender,
      TPlannerItem *Item)
{
     // if(Item->ItemPos==0)
     AnsiString ss;
     ss=Item->Text->Text;
//  Item->Color = clRed;
     Planner1->UpdateItem(Item);
     //Item->Color = clRed;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Shed::FormShow(TObject *Sender)
{
//   Planner1->Mode->PeriodStartDate =
//   Planner1->Mode->TimeLineStart

float prop_h, prop_w;

prop_h = 1.2;
prop_w = 1.68;
Width = Screen->Width/prop_w;

if(Screen->Height/prop_h >700)
Height= Screen->Height/prop_h;
else {if(Screen->Height>700) Height=700; else Height=Screen->Height;}

Top = (Screen->Height - Height)/2;
Left= (Screen->Width - Width)/2;
double d1,d2,d3;
AnsiString ss1,ss2,ss3,ss4,s1;
int index,du,shag1,ID,CabID, per;
unsigned short hh1,mm1,sss1,mss1 ;
TDateTime dd1;
TColor colprev;
//d1 =
//Planner1->Mode->TimeLineStart=d_b;
d1=d_b;
TPlannerItem *plIt,*plCab;
 TPositionProp *plPr;
 du=30;//Planner1->Display->DisplayUnit;
   d_b.DecodeTime(&hh1,&mm1,&sss1,&mss1);
       Planner1->Display->ActiveStart = 2*hh1-18;
       d_end.DecodeTime(&hh1,&mm1,&sss1,&mss1);
       Planner1->Display->ActiveEnd = 2*hh1-18;

// d_end=d1+((Planner1->Display->DisplayEnd)/24.)/du;

  ss1=DateTimeToStr(d1);
 shag1=2;
 show_form=true;
 /*if(Data1->Write_cab->RecordCount>0 )
   {
           ShowMessage("������ �����������!!!��� ���� ������ ������� ����� � ���� �������!");
           }   */
for(Data1->Write_cab->First() ;!Data1->Write_cab->Eof ;Data1->Write_cab->Next() )

{
d1=Data1->Write_cab->FieldByName("Date_w")->AsFloat;
d2=Data1->Write_cab->FieldByName("Date_end")->AsFloat;
ID=Data1->Write_cab->FieldByName("ID")->AsInteger;
per=Data1->Write_cab->FieldByName("PerID")->AsInteger;
Data1->Temp->Close();
Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add("Select Name from Personal where ID="+ IntToStr(per));
Data1->Temp->Open();
ss2=" ";
if(Data1->Temp->RecordCount>0 )
     ss2=Data1->Temp->FieldByName("Name")->AsString;
ss2=ss2.Trim();
ss1="������ "+ss2;
dd1=d1;
dd1.DecodeTime(&hh1,&mm1,&sss1,&mss1);

if(mm1==15||mm1==45)
{
 du=15;
 shag1=4;
}
dd1=d2;
dd1.DecodeTime(&hh1,&mm1,&sss1,&mss1);

if(mm1==15||mm1==45)
{
 du=15;
 shag1=4;
}
    Form_Shed->Planner1->Display->DisplayUnit=du;


for(int j=0;j<4;j++)
 {

plCab=Planner1->Items->Add() ;
 if(j==0)
     plCab->Text->Text = ss2.Trim() ;


plCab->CaptionType=ctNone;

  plCab->ShowDeleteButton =true;
  plCab->Selected =false;
  plCab->Shape = psTool;
  plCab->ShowSelection =false;
  plCab->TrackVisible =false;
   plCab->CompletionDisplay = cdNone;
 plCab->Shadow =false;
 index=(d1 - Planner1->Mode->TimeLineStart)*1440;//*shag1*24;
 index=index/du;
// index-=1;
 plCab->ItemBegin =index;
if(d2==0)
  plCab->ItemEnd= index+1;
else
 {
  index=(d2 - Planner1->Mode->TimeLineStart)*1440;//shag1*24;
  index=index/du;
 //index-=1;
  plCab->ItemEnd= index;
 }
 plCab->ItemPos = j;
 plCab->Color =clRed;
 plCab->ReadOnly=true;
 plCab->Visible = true;
  plCab->ID=7777;//�������

 }

}//  for(int i=0;i<Data1->Write_cab->RecordCount;i++)

if(Data1->Shed_daily->RecordCount!=0)
{
Data1->Shed_daily->First();
colprev=clYellow;



for(int i=0;i<Data1->Shed_daily->RecordCount;i++)
{
d1=Data1->Shed_daily->FieldByName("Date_w")->AsFloat;
d2=Data1->Shed_daily->FieldByName("Date_end")->AsFloat;
ID=Data1->Shed_daily->FieldByName("ID")->AsInteger;
CabID=Data1->Shed_daily->FieldByName("CabID")->AsInteger;
dd1=d1;
dd1.DecodeTime(&hh1,&mm1,&sss1,&mss1);

if(mm1==15||mm1==45)
{
 du=15;
 shag1=4;
}
dd1=d2;
dd1.DecodeTime(&hh1,&mm1,&sss1,&mss1);

if(mm1==15||mm1==45)
{
 du=15;
 shag1=4;
}


// d3 =  modf(d1,&d2);
// d3=2*d3*86400./3600.;
 ss1=Data1->Shed_daily->FieldByName("Name")->AsString;//FieldValues["Name"];
ss2=Data1->Shed_daily->FieldByName("Comment")->AsString;
ss3=Data1->Shed_daily->FieldByName("Phone")->AsString;
ss4=Data1->Shed_daily->FieldByName("Prim")->AsString;
ss1=ss1.Trim();
ss4=ss4.Trim();
 if(ss4=="0") ss4="";

 Form_Shed->Planner1->Display->DisplayUnit=du;

 /*
 if(i==0)
      colprev=clYellow;
else
 {
 if(colprev==clYellow)
   colprev=clGreen;
 else
    colprev=clYellow;
 }
  */
for(int j=0;j<4;j++)
 {
// ss1=ss1.Trim();
 if(!ss1.IsEmpty()&&ss1!="0"  ){


 plIt=Planner1->Items->Add() ;
 plIt->CaptionType=ctNone;

 //plIt->Index=10;
  plIt->ShowDeleteButton =true;
  plIt->Selected =false;
  plIt->Shape = psTool;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
   plIt->CompletionDisplay = cdNone;
 plIt->Shadow =false;
// index=(d1 - Planner1->Display->ActiveStart)*shag1*24;
s1=DateTimeToStr(Planner1->Mode->TimeLineStart);
 index=(d1 - Planner1->Mode->TimeLineStart)*1440;//*shag1*24;
 index=index/du;
 //index-=1;

 plIt->ItemBegin =index;
if(d2==0)
  plIt->ItemEnd= index+1;
else
 {
  index=(d2 - Planner1->Mode->TimeLineStart)*shag1*24;
 index=(d2 - Planner1->Mode->TimeLineStart)*1440;//*shag1*24;
 index=index/du;
// index-=1;
  plIt->ItemEnd= index;
 }
 plIt->ItemPos = j;
 plIt->Color =colprev;


 if(CabID==Form_Calndr->CabID) {
 plIt->ReadOnly=false;
 if(j==0)
    plIt->Text->Text = ss1.Trim() ;
  if(j==1)
     plIt->Text->Text = ss2.Trim() ;
  if(j==2)
     plIt->Text->Text = ss3.Trim() ;
  if(j==3)
     plIt->Text->Text = ss4.Trim() ;
 plIt->ID=ID;
                               }

else{
Data1->Temp->Close();
Data1->Temp->SQL->Clear();
Data1->Temp->SQL->Add("Select Name from Cabinet where ID="+ IntToStr(CabID));
Data1->Temp->Open();
ss2=" ";
if(Data1->Temp->RecordCount>0 )
     ss2=Data1->Temp->FieldByName("Name")->AsString;
ss2=ss2.Trim();
ss1="������ � "+ss2;
 if(j==0)
    plIt->Text->Text = ss2;

plIt->Color =clRed;
plIt->ID=7777;

}
 plIt->Visible = true;

  }

                       }



if(colprev==clYellow)
   colprev=clGreen;
 else
    colprev=clYellow;



Data1->Shed_daily->Next();
}
 }
  index=  Planner1->Items->Count;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::Planner1PlannerSelectCell(TObject *Sender,
      int Index, int Pos, bool &CanSelect)
{
// ShowMessage("RRR");
if(show_form)
{
TDateTime d1;
AnsiString ss,tel;
TPlannerItem *plIt;
int n1, n2;
//Planner1->CreateItem() ;
// TPoint  pt;
// pt= Planner1->XYToCell(Pos,Index);
 //Planner1->SelItemBegin()
 n1=Planner1->Display->ActiveStart;
  n2=Planner1->Display->ActiveEnd;
//if (!Planner1->Items->HasItem(Index,Index+1,Pos-1))
if(Index>=n1 && Index<=n2)
{


 float hh1;
// TDateTime d1;
      d_curr=Planner1->Mode->TimeLineStart;
      ss=DateTimeToStr(d_b);
      tel=DateTimeToStr(d_end);


      hh1=Index*du;
 hh1=hh1*60.;
 d_curr=d_curr+hh1/86400.;
       ss=DateTimeToStr(d_curr);

    if(Form_About->ShowModal()==1)
    {
for(int j=0;j<4;j++)
 {

plIt=Planner1->Items->Add() ;
 plIt->ReadOnly=false;
 ItemIndex=Index+1;
 plIt->ID=0;

 plIt->ItemBegin =Index;
 plIt->ItemEnd=plIt->ItemBegin+ shag/du;


 plIt->ItemPos = j;
 plIt->Shadow =true;
 plIt->Selected =false;
  plIt->Shape = psTool;
  plIt->ShowSelection =false;
  plIt->TrackVisible =false;
  plIt->Background = true;
   plIt->SelectFontColor = clBlack;

    if(j==0 )
    {
       plIt->Text->Text =Form_About->Name ;


     }
     if(j==2 )
    {
            plIt->Text->Text =Form_About->Phone;
    }

     if(j==3 )
    {
            plIt->Text->Text =Form_About->Prim;
    }

if(j==1 )
{
            plIt->Text->Text =Form_About->Comment;

 }



}

ReShed(Form_About->shag);
shag=Form_About->shag;
     }// if(Form_About->ShowModal()==mrOK)

  }
// plIt->ItemPos=DayPlanner->SelPosition;
 //plIt->ItemBegin=DayPlanner->SelItemBegin;
// plIt->ItemEnd=DayPlanner->SelItemEnd;


}//show_form
}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::BitBtn1Click(TObject *Sender)
{
//
/*
Variant v[7]={0,0,0,0,0,0,0};
v[0]=Form_Pers->PerID;
int n_it,shag1;

du=Planner1->Display->DisplayUnit;
if(du==15) shag1=4;
else shag1=2;


TDateTime d1;
AnsiString ss,s1;
n_it = Planner1->Items->Count;
//n_it = PlannerMonthView1->Items->NumItemsAtDate(SelDate) ;
TPlannerItem *plIt;

for(int i=0;i<n_it;i++)
    {
     plIt=Planner1->Items->Items[i];

    Planner1->UpdateItem(plIt);

if(plIt->ID==0)
 {
  ss=plIt->Text->Text.Trim();
    if(plIt->ItemPos==0)
    {
     if(!ss.IsEmpty() && ss!="0" ){
    ss=DateTimeToStr(plIt->ItemStartTime);
    d1=Planner1->Mode->TimeLineStart;
       ss=DateTimeToStr(d1);
d1+=  ((plIt->ItemBegin)*3600./86400.)/shag1;
    ss=DateTimeToStr(d1);
    v[4]=d1;//plIt->ItemStartTime;
    v[1]=plIt->Text->Text.Trim();
    }}

    if(plIt->ItemPos==1)
    {
      v[3]=plIt->Text->Text.Trim() ;
          d1=Planner1->Mode->TimeLineStart;
    d1+=  ((plIt->ItemBegin)*3600./86400.)/shag1;
    ss=DateTimeToStr(d1);
    v[4]=d1;//plIt->ItemStartTime;

    d1=Planner1->Mode->TimeLineStart;
     d1+= ((plIt->ItemEnd)*3600./86400.)/shag1;
    v[5]=d1;

    }
    if(plIt->ItemPos==2)
        v[2]=plIt->Text->Text.Trim();
    if(plIt->ItemPos==3)
        v[6]=plIt->Text->Text.Trim();
  }
    }
if(n_it>0 && v[1]!=Null()&& plIt->ID==0)
{
Data1->Writer->Close();

for(int j=0;j<7;j++)
Data1->Writer->Parameters->Items[j]->Value  = v[j];

Data1->Writer->Prepared = true;
Data1->Writer->ExecSQL();

}


////
for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
if(plIt->ID!=0)
   {
   ss=plIt->Text->Text.Trim();
   Data1->Temp->Close();
Data1->Temp->SQL->Clear();
if(plIt->ItemPos==0)
 s1="Update Write_Client set Name='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==1)
 s1="Update Write_Client set Comment='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==2)
 s1="Update Write_Client set Phone='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==3)
 s1="Update Write_Client set Prim='" +ss+"' where ID="+ IntToStr(plIt->ID);

 Data1->Temp->SQL->Add(s1);
 Data1->Temp->ExecSQL();
   }

    Planner1->UpdateItem(plIt);
    }
                */
WriteClient();

int shag,n_it;
shag=30;

n_it = Planner1->Items->Count;
TPlannerItem *plIt;



for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
if(plIt->ID==0)
            plIt->ID=9999;
    Planner1->UpdateItem(plIt);
   }

   ShowMessage("������� ��������");
int sel;
    sel=Application->MessageBox("��������� �����?","�����",MB_YESNO);
if(sel==6)
        Button1Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        //planner1.Items.EndUpdate;
        BitBtn1->SetFocus();




WriteClient();

Planner1->Items->ClearAll();
Form_Calndr->PlannerMonthView1->Items->UnSelectAll() ;
      // Form_main->RadioGroup1->ItemIndex =0;

shag=30;
show_form=false;
}
//---------------------------------------------------------------------------

void TForm_Shed::WriteClient()
{
Variant v[8]={0,0,0,0,0,0,0,0};
v[0]=Form_Pers->PerID;
v[7]=Form_Calndr->CabID;
int n_it,shag1,Pos;
double hh1;
Pos=-1;
du=Planner1->Display->DisplayUnit;

if(du==15)
shag1=4;
else shag1=2;

TDateTime d1;
AnsiString ss,s1;
n_it = Planner1->Items->Count;
//n_it = PlannerMonthView1->Items->NumItemsAtDate(SelDate) ;
TPlannerItem *plIt,*plIt0;
//plIt=Planner1->Items->Items[n_it-1];
//Planner1ItemEndEdit(Sender,plIt);

for(int i=0;i<n_it;i++)
    {
     plIt0=Planner1->Items->Items[i];
  if(plIt0->ID==0 && plIt0->ItemBegin!=Pos)
 {
   Pos=plIt0->ItemBegin;
//   n_it=Planner1->Items->ItemsAtPosition(plIt0->ItemPos);
for(int k=1;k<7;k++)
     v[k]=0;
  for(int j=0;j<4;j++)
   {
   plIt = Planner1->Items->FindFirst(plIt0->ItemBegin,plIt0->ItemEnd,j);
   if(plIt)
  {
   ss=plIt->Text->Text.TrimRight() ;
   if(j==0)
   {
    v[1]=plIt->Text->Text.TrimRight();
     d1=Planner1->Mode->TimeLineStart;
//     d1+= ((plIt->ItemBegin)*3600./86400.)/shag1;
        hh1=plIt->ItemBegin*du;
 hh1=hh1*60.;
     d1+= hh1/86400.;

     ss=DateTimeToStr(d1);

    v[4]=d1;//plIt->ItemStartTime;
    d1=Planner1->Mode->TimeLineStart;
//     d1+= ((plIt->ItemEnd)*3600./86400.)/shag1;
        hh1=plIt->ItemEnd*du;
 hh1=hh1*60.;
     d1+= hh1/86400.;

    v[5]=d1;

   }
   if(j==1)
   {
    v[3]=plIt->Text->Text.TrimRight() ;
     d1=Planner1->Mode->TimeLineStart;

      hh1=plIt->ItemBegin*du;
 hh1=hh1*60.;
     d1+= hh1/86400.;
      ss=DateTimeToStr(d1);
    v[4]=d1;//plIt->ItemStartTime;
     d1=Planner1->Mode->TimeLineStart;
      hh1=plIt->ItemEnd*du;
 hh1=hh1*60.;
     d1+= hh1/86400.;
//     d1+= ((plIt->ItemEnd)*3600./86400.)/shag1;
    v[5]=d1;
   }
   if(j==2)
    v[2]=plIt->Text->Text.TrimRight();
   if(j==3)
    v[6]=plIt->Text->Text.TrimRight();
   }

   }        //end for j
       ss=v[1];

      // Pos=ss.Length();
      bool kk;
       kk=ss.IsEmpty();
if(!kk)
{
Data1->Writer->Close();

for(int j=0;j<8;j++)
Data1->Writer->Parameters->Items[j]->Value  = v[j];

Data1->Writer->Prepared = true;
Data1->Writer->ExecSQL();

}


 }
    }


for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
   if(plIt->ID!=0&&plIt->ID!=7777)
   {
   ss=plIt->Text->Text.TrimRight();
   Data1->Temp->Close();
Data1->Temp->SQL->Clear();
if(plIt->ItemPos==0)
 s1="Update Write_Client set Name='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==1)
 s1="Update Write_Client set Comment='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==2)
 s1="Update Write_Client set Phone='" +ss+"' where ID="+ IntToStr(plIt->ID);
if(plIt->ItemPos==3)
 s1="Update Write_Client set Prim='" +ss+"' where ID="+ IntToStr(plIt->ID);

 Data1->Temp->SQL->Add(s1);
 Data1->Temp->ExecSQL();
   }

    Planner1->UpdateItem(plIt);
    }



}
//////////////////////


void __fastcall TForm_Shed::BitBtn2Click(TObject *Sender)
{

Planner1->PrintOptions->Header->Text =Planner1->Caption->Title;
 if (PrintDialog1->Execute()) Planner1->Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::Button1Click(TObject *Sender)
{
//


Close();
Form_Calndr->Close();                       }
//---------------------------------------------------------------------------




void __fastcall TForm_Shed::N151Click(TObject *Sender)
{
//
  /*
int n_it;
TDateTime d1;
AnsiString ss;
n_it = Planner1->Items->Count;
TPlannerItem *plIt;
 TPositionProp *plPr;
for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
    plIt->ItemEnd=plIt->ItemBegin+ 2;

    }

//     Planner1->Posi
plPr =     Planner1->PositionProps->Items[0];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
plPr =     Planner1->PositionProps->Items[1];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
plPr =     Planner1->PositionProps->Items[2];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
*/

}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::DBGrid1DblClick(TObject *Sender)
{
//
int n_it,ind;
TDateTime d1;
//AnsiString ss;
n_it = Planner1->Items->Count;
TPlannerItem *plIt;
 TPositionProp *plPr;
if(Data1->WriServ->RecordCount!=0)
{
       ServName=Data1->WriServ->FieldValues["ServName"];
       shag=Data1->WriServ->FieldByName("ServTime")->AsInteger;
       if(shag==15||shag==45)
         du=15;//Planner1->Display->DisplayUnit =15;
if(shag==30||shag==60)
         du=30;//Planner1->Display->DisplayUnit =30;

//du=Planner1->Display->DisplayUnit;
       if(shag!=15&&shag!=45&&Planner1->Display->DisplayUnit==15)    shag*=2;

for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
    ind=plIt->ItemBegin+1;
    if(plIt->ID==0&&ItemIndex==ind)
    {
    if(du==15)
    Planner1->Display->DisplayUnit=du;
    ItemIndex=plIt->ItemBegin+1;
             plIt->ItemEnd=plIt->ItemBegin+ shag/du;;
        if(plIt->ItemPos==1)    {          plIt->Text->Text=ServName;
                               /*
            plPr =     Planner1->PositionProps->Add();//Items[0];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
plPr =     Planner1->PositionProps->Add();//Items[1];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
plPr =     Planner1->PositionProps->Add();//Items[2];
     plPr->ActiveStart=plIt->ItemBegin;
     plPr->ActiveEnd=plIt->ItemEnd;
     plPr->ColorActive = clYellow;
                             */
    /*
    Planner1->ShowSelection =true;
      Planner1->SelItemBegin =plIt->ItemBegin;
      Planner1->SelItemEnd =plIt->ItemEnd;
      */
}

     }
    }

 }

      DBGrid1->Enabled = false;
      DBGrid1->Visible =false;

}
//---------------------------------------------------------------------------



void __fastcall TForm_Shed::DBGrid1KeyPress(TObject *Sender, char &Key)
{
//
if (Key==VK_ESCAPE)
{
     DBGrid1->Enabled = false;
     DBGrid1->Visible =false;
     Planner1->SetFocus() ;
}
if(Key==VK_RETURN)
  DBGrid1DblClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Shed::Planner1ItemRightClick(TObject *Sender,
      TPlannerItem *Item)
{
//
AnsiString s1;
int sel;
if(Item->ID!=7777)
{
    sel=Application->MessageBox("�� ������������� ������ ������� ��� ������?","��������",MB_YESNO);
if(sel==6)
{
Data1->Temp->Close();
Data1->Temp->SQL->Clear();
s1="Delete from Write_Client where ID="+ IntToStr(Item->ID);
Data1->Temp->SQL->Add(s1);
Data1->Temp->ExecSQL();

Item->ItemPos;
Item->ItemBegin;
Item->ItemEnd;
Item->Index;
int n_it;
n_it = Planner1->Items->Count;
TPlannerItem *plIt0, *plIt;
 for(int i=0;i<n_it;i++)
    {
     plIt0=Planner1->Items->Items[i];
     if(plIt0->ItemBegin==Item->ItemBegin)
          {

          for(int j=0;j<4;j++)
   {

       //>Delete(Item->Index);
   plIt = Planner1->Items->FindFirst(plIt0->ItemBegin,plIt0->ItemEnd,j);
   if(plIt)
   plIt->Free();
  // Planner1->Items->FindNext() 
    }


    i=n_it; }         }

}}
}
//---------------------------------------------------------------------------


void TForm_Shed::ReShed(int shag)
{
//
int n_it,ind;
TDateTime d1;

n_it = Planner1->Items->Count;
TPlannerItem *plIt;
 TPositionProp *plPr;
       if(shag==15||shag==45)
         du=15;//Planner1->Display->DisplayUnit =15;
if(shag==30||shag==60)
         du=30;//Planner1->Display->DisplayUnit =30;

//du=Planner1->Display->DisplayUnit;
 if(shag!=15&&shag!=45&&Planner1->Display->DisplayUnit==15)    shag*=2;

for(int i=0;i<n_it;i++)
    {
    plIt=Planner1->Items->Items[i];
    ind=plIt->ItemBegin+1;
    if(plIt->ID==0&&ItemIndex==ind)
    {
    if(du==15)
    Planner1->Display->DisplayUnit=du;
    ItemIndex=plIt->ItemBegin+1;
             plIt->ItemEnd=plIt->ItemBegin+ shag/du;;


     }
    }




}
//---------------------------------------------------------------------------




//---------------------�����------------------------------------------------------




void __fastcall TForm_Shed::Planner1PlannerDblClick(TObject *Sender,
      int Position, int FromSel, int FromSelPrecise, int ToSel,
      int ToSelPrecise)
{
//ShowMessage("dddd");
}
//---------------------------------------------------------------------------




