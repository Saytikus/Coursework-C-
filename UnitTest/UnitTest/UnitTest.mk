##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UnitTest
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/stud/C++Projects/Kursach!client/Kursach!client
ProjectPath            :=/home/stud/C++Projects/Kursach!client/UnitTest/UnitTest
IntermediateDirectory  :=../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest
OutDir                 :=../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=12/26/22
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../../Kursach!client/build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/unittest++ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)crypto++ $(LibrarySwitch)boost_system $(LibrarySwitch)UnitTest++ $(LibrarySwitch)stdc++fs 
ArLibs                 :=  "crypto++" "boost_system" "libUnitTest++.a" "libstdc++fs" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/.d $(Objects) 
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest"
	@mkdir -p ""../../Kursach!client/build-$(ConfigurationName)/bin""

../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/.d:
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest"

PreBuild:


##
## Objects
##
../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(ObjectSuffix): main.cpp ../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/UnitTest/UnitTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(DependSuffix) -MM main.cpp

../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest/main.cpp$(PreprocessSuffix) main.cpp


-include ../../Kursach!client/build-$(ConfigurationName)/__/UnitTest/UnitTest//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


