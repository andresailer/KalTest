# v02-02
F.Gaede
-  made compatible with c++11 and ROOT6
- removed -ansi -pedantic -Wno-long-long
- added current source dir to include path for dictionary built

# v02-01
F.Gaede
- default measurement dimension (kSdim) set to 5
- added flag BUILD_WITH_T0_FIT (default OFF) setting the measurement dimension to 6 
- TKalDetCradle.cxx
- bug fix for intersection calculation using the newtonian solver such as cones for example (reseting the deflection angle to 0 in TKalDetCradle::Transport()) 

# v02-00
- implemented the optional use of a non-uniform B field ( Li Bo) as described in  Bo Li, Keisuke Fujii, Yuanning Gao, ("Kalman-filter-based track fitting in non-uniform magnetic field with segment-wise helical track model")[http://arxiv.org/abs/1305.7300]


# v01-05-04
- Fixed a field direction bug  (Bo Li)
- Slightly modified the track model class to make the straight track work; Straight track generation is the example ct was implemented.  (Bo Li)

# v01-05-03
- apply bug fix provided by K.Fujii that makes adjusting of the z0 for curlers in ThelicalTrack::MoveTo unnecessary

# v01-05-01
- Fixed orientation for in/out transportation in TKalDetCradle, previously only inward transportation was correct.
- Ensure that material effects are treated correctly by only including material effects from present surface to destination surface.
- THelicalTrack:MoveTo modified to make sure the helix really moves to the new reference point and is not out by more than 2PI.

# v01-05
- Added TCutCone surface with examples of use in hybrid example.
- ScatterBy function corrected in TVTrack class.

# v01-04
- geomlib 
- TCylinder IsOnSurface now checks if point is on the surface (r) not just between +/-z

# v01-03
- added name member and corresponding getName memeber function to TVMeasLayer

# v01-02
- modified to use bounded planes
- examples provided in hybrid example to demonstrate use of bounded planes in VXD and FTD 
- added extra Transport method to transport directly to a measurement layer and modified the  previous Transport to site method to use this method. No change in previous functionality, only additional functionality added
            	
# v01-01-01
- fixed problem in KalTest VERSION


# v01-01
- fixed problem from MacroRootDict.cmake: LD_LIBRARY_PATH unset with rootcint
- improved cmake files
- requires new package ILCUTIL


# v01-00
- first release as part of iLCSoft
- introduced new default units: mm, Tesla (was cm, kGauss)
- introduced cmake build files
- updated examples/kaltest/hybrid/main/EXKalTest.cxx to write track parameters d0 and tnl and errors^2 to ntuple
- Note: default units are not yet changed in example, thus the detector is scaled to 1/10 of its size with the BField 10 times larger ...
