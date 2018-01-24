#pragma once

#include <vector>
#include <memory>
#include "disassembler.h"

class Signature {
public:
	Signature(std::string sCVE) : sCVE(sCVE) {}

public:
	inline void addPostiveString(std::string& sPostiveString) {
		vPostiveStrings.push_back(sPostiveString);
	}

	inline void addNegativeString(std::string& sNegativeString) {
		vNegativeStrings.push_back(sNegativeString);
	}

	inline void addPostiveASM(std::string& sPostiveASM) {
		vPostiveASM.push_back(sPostiveASM);
	}

	inline void addNegativeASM(std::string& vNegativeASM) {
		vNegativeStrings.push_back(vNegativeASM);
	}

	inline std::string getCVE() { return sCVE; }


	bool stringMatch(const std::vector<std::string>& vLookupStrings);
	bool asmCodeMatch(const Disassembler::InstructionSet& instructionSet);

private:
	std::string sCVE;
	std::vector<std::string> vPostiveStrings;
	std::vector<std::string> vNegativeStrings;
	std::vector<std::string> vPostiveASM;
	std::vector<std::string> vNegativeASM;
};

class SignatureLoader {
public:
	SignatureLoader() {};

public:
	bool load(std::string sSigsFilePath);
	inline size_t getSize() {
		return vspSignatures.size();
	}

	inline Signature* getSignature(size_t index) {
		return vspSignatures.at(index).get();
	};

private:
	std::vector<std::shared_ptr<Signature>> vspSignatures;
};