#!/usr/bin/env python

import ROOT as rt
import os
import sys

def main():
	try:
		rt.gSystem.Load(os.path.join(os.getenv('VOLKERDIR'), 'lib/libMyUtils'))
	except:
		print >> sys.stderr, '[e] unable to load libMyUtils... $VOLKERDIR not set? trying to guess..'
		guess_dir = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'lib')
		print '[i] guessed lib dir is', guess_dir

		try:
			rt.gSystem.Load(os.path.join(guess_dir, 'libMyUtils'))
		except:
			print >> sys.stderr, '[e] unable to load libMyUtils...'
			return

	print '[i] start...'

	ut = rt.MyUtils("called_from_python")
	ut.Loop(200)

	print '[i] done.'

if __name__ == '__main__':
	main()

