##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Kursach
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/stud/C++Projects/Kursach!client/Kursach!client
ProjectPath            :=/home/stud/C++Projects/Kursach!client/Kursach/Kursach
IntermediateDirectory  :=../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach
OutDir                 :=../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=12/23/22
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)crypto++ $(LibrarySwitch)boost_system 
ArLibs                 :=  "crypto++" "boost_system" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(ObjectSuffix) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(ObjectSuffix) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(ObjectSuffix) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(ObjectSuffix) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(ObjectSuffix) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/.d $(Objects) 
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach"
	@mkdir -p ""../../Kursach!client/build-$(ConfigurationName)/bin""

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/.d:
	@mkdir -p "../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach"

PreBuild:


##
## Objects
##
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(ObjectSuffix): main.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(DependSuffix) -MM main.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/main.cpp$(PreprocessSuffix) main.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(ObjectSuffix): User.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/User.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(DependSuffix): User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(DependSuffix) -MM User.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(PreprocessSuffix): User.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/User.cpp$(PreprocessSuffix) User.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(ObjectSuffix): UserHandler.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/UserHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UserHandler.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(DependSuffix): UserHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(DependSuffix) -MM UserHandler.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(PreprocessSuffix): UserHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/UserHandler.cpp$(PreprocessSuffix) UserHandler.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(ObjectSuffix): TestClass.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/TestClass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TestClass.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(DependSuffix): TestClass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(DependSuffix) -MM TestClass.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(PreprocessSuffix): TestClass.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TestClass.cpp$(PreprocessSuffix) TestClass.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(ObjectSuffix): Interface.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/Interface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Interface.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(DependSuffix): Interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(DependSuffix) -MM Interface.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(PreprocessSuffix): Interface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/Interface.cpp$(PreprocessSuffix) Interface.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(ObjectSuffix): TCPclient.cpp ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Kursach!client/Kursach/Kursach/TCPclient.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TCPclient.cpp$(ObjectSuffix) $(IncludePath)
../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(DependSuffix): TCPclient.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(ObjectSuffix) -MF../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(DependSuffix) -MM TCPclient.cpp

../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(PreprocessSuffix): TCPclient.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach/TCPclient.cpp$(PreprocessSuffix) TCPclient.cpp


-include ../../Kursach!client/build-$(ConfigurationName)/__/Kursach/Kursach//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


