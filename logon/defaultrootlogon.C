void defaultrootlogon()
{
  //  std::cout << "Loading CMS-specific Libraries." << std::endl;

  std::cout << "Add User-specific Libraries." << std::endl;
  gSystem->AddIncludePath("-I/Users/johnpaul/Work/myroot/include");
  gSystem->AddDynamicPath("/Users/johnpaul/Work/myroot/lib");
  gSystem->Load("libmyroot.so");

  std::cout << "Setup style" << std::endl;

  const float FONTSIZE = 0.05;

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(1111110);
  gStyle->SetLabelFont(42, "X");
  gStyle->SetLabelFont(42, "Y");
  gStyle->SetLabelFont(42, "Z");
  gStyle->SetLabelSize(0.045, "X");
  gStyle->SetLabelSize(0.045, "Y");
  gStyle->SetLabelSize(0.045, "Z");
  gStyle->SetNdivisions(510,"X");
  gStyle->SetNdivisions(510,"Y");
  gStyle->SetNdivisions(510,"Z");
  gStyle->SetLabelOffset(0.007,"X");
  gStyle->SetLabelOffset(0.007,"Y");
  gStyle->SetLabelOffset(0.007,"Z");
  gStyle->SetTextFont(42);
  gStyle->SetTextSize(FONTSIZE);
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleFont(42,"Z");
  gStyle->SetTitleFont(42,"T");
  gStyle->SetTitleX(0.3);
  gStyle->SetTitleY(0.985);
  gStyle->SetTitleW(0);
  gStyle->SetTitleH(0);
  gStyle->SetTitleOffset(1.1,"y") ;
  gStyle->SetTitleOffset(1.1,"x") ;
  gStyle->SetTitleXSize(FONTSIZE);
  gStyle->SetTitleYSize(FONTSIZE);
  gStyle->SetTitleSize(0.10);
  gStyle->SetTitleSize(FONTSIZE,"x");
  gStyle->SetTitleSize(FONTSIZE,"y");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleColor(1);
  //  gStyle->SetErrorMarker( 8 );
  gStyle->SetPaperSize(TStyle::kUSLetter) ;

  gStyle->SetLegendFont(42);
  gStyle->SetLegendBorderSize(0);
  
  gStyle->SetCanvasBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(600); //Height of canvas
  gStyle->SetCanvasDefW(600); //Width of canvas

  gStyle->SetPadBorderMode(0) ;
  gStyle->SetPadColor(kWhite);
  gStyle->SetPadGridX(false);
  gStyle->SetPadGridY(false);
  gStyle->SetGridColor(0);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);
  gStyle->SetPadBottomMargin(0.13);
  gStyle->SetPadTopMargin(0.07);
  gStyle->SetPadLeftMargin(0.14);
  gStyle->SetPadRightMargin(0.08);
  //gStyle->SetPadTickX( 1 );
  gStyle->SetPadTickY( 1 );
  
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameLineColor(1);
  gStyle->SetFrameLineStyle(1);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameBorderSize(1);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameFillStyle(0);

 
  // gStyle->SetFitFormat("6.4f");
  // gStyle->SetStatFormat("6.4f");
  gStyle->SetStatFont(42) ;
  gStyle->SetStatFontSize(0.025) ;
  gStyle->SetStatX(0.87) ; 
  gStyle->SetStatY(0.87) ; 
  gStyle->SetStatW(0.28);
  gStyle->SetStatH(0.30);
  gStyle->SetStatBorderSize(0) ;
  gStyle->SetStatColor(0) ;
  gStyle->SetStatStyle(0);
  //gStyle->SetStatStyle(4001);
  // gStyle->SetTextAlign(13);
  gStyle->SetHistFillColor(5);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineStyle(0);
  gStyle->SetLineWidth(1);
  gStyle->SetFuncWidth(1);
  gStyle->SetDrawBorder(2);

  
  gStyle->SetPalette(kDeepSea);
  
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(0.5);
  gROOT->ForceStyle();
}
