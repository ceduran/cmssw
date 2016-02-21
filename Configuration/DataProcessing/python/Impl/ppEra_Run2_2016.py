#!/usr/bin/env python
"""
_ppEra_Run2_2016_

Scenario supporting proton collisions

"""

import os
import sys

from Configuration.DataProcessing.Reco import Reco
import FWCore.ParameterSet.Config as cms
import Configuration.StandardSequences.Eras as eras

from Configuration.DataProcessing.Impl.pp import pp

class ppEra_Run2_2016(pp):
    def __init__(self):
        pp.__init__(self)
        self.recoSeq=''
        self.cbSc='pp'
        self.eras=eras.eras.Run2_2016
        self.promptCustoms += [ 'Configuration/DataProcessing/RecoTLR.customisePostEra_Run2_25ns' ]
        self.expressCustoms += [ 'Configuration/DataProcessing/RecoTLR.customisePostEra_Run2_25ns' ]
        self.visCustoms += [ 'Configuration/DataProcessing/RecoTLR.customisePostEra_Run2_25ns' ]
    """
    _ppEra_Run2_2016_

    Implement configuration building for data processing for proton
    collision data taking for Run2

    """
