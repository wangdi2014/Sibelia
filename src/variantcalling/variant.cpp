//****************************************************************************
//* Copyright (c) 2012 Saint-Petersburg Academic University
//* All Rights Reserved
//* See file LICENSE for details.
//****************************************************************************

#include "variant.h"

namespace SyntenyFinder
{
	const size_t Variant::UNKNOWN_BLOCK = -1;

	Variant::Variant(size_t refPos, size_t blockId, const std::string & refAllele, const std::string & altAllele):
		refPos_(refPos), blockId_(blockId), refAllele_(refAllele), altAllele_(altAllele)
	{

	}

	bool Variant::operator < (const Variant & toCompare) const
	{
		return refPos_ < toCompare.refPos_;
	}

	void Variant::ToString(std::string & buf) const
	{
		std::stringstream ss;
		ss << refPos_ << '\t' << (refAllele_.empty() ? "." : refAllele_) << '\t' << (altAllele_.empty() ? "." : altAllele_) << '\t' << blockId_;
		buf = ss.str();
	}
}