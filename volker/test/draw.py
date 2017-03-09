#!/usr/bin/env python -i

import ROOT as rt

gList = []

def main():
	rt.gStyle.SetOptTitle(0)
	global gList
	tc = rt.TCanvas('draw_test', 'draw_test', 500, 500)
	tc.cd()
	fnames = [ 'called_from_ROOT.root', 'called_from_c_function.root', 'called_from_python.root', 'called_from_test1_Volker_exec.root']
	sopt = ''
	for i, fname in enumerate(fnames):
		fin = rt.TFile(fname)
		if fin:
			gList.append(fin)
			h = fin.Get('fHdummy')
			if h:
				h.SetMarkerStyle(i + 20)
				h.SetMarkerColor(i + 1)
				h.SetMarkerSize(0.9)
				h.SetLineColor(i + 1)
				h.Scale(1./h.Integral())
				h.Draw(sopt)
				sopt = 'same'
				gList.append(h)
	rt.gPad.BuildLegend(0.15, 0.4, 0.5, 0.6)
	rt.gPad.SetLogy()
	rt.gPad.Update()
	gList.append(tc)

if __name__ == '__main__':
	main()
