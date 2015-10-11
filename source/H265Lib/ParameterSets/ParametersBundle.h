#pragma once

#include <ParameterSets/PictureParameterSet.h>

namespace H265Lib
{
	struct ParametersBundle
	{
		std::shared_ptr<VideoParameterSet> Vps;
		std::shared_ptr<PictureParameterSet> Pps;
		std::shared_ptr<SequenceParameterSet> Sps;

		ParametersBundle() :
			Vps(nullptr),
			Pps(nullptr),
			Sps(nullptr)
		{

		}

		ParametersBundle(std::shared_ptr<VideoParameterSet> vps) :
			Vps(vps),
			Pps(nullptr),
			Sps(nullptr)
		{

		}

		ParametersBundle(std::shared_ptr<SequenceParameterSet> sps) :
			Vps(nullptr),
			Pps(nullptr),
			Sps(sps)
		{

		}

		ParametersBundle(std::shared_ptr<PictureParameterSet> pps) :
			Vps(nullptr),
			Pps(pps),
			Sps(nullptr)
		{

		}

		ParametersBundle(std::shared_ptr<SequenceParameterSet> sps, std::shared_ptr<PictureParameterSet> pps) :
			Vps(nullptr),
			Pps(pps),
			Sps(sps)
		{

		}

		ParametersBundle(std::shared_ptr<VideoParameterSet> vps, std::shared_ptr<SequenceParameterSet> sps, std::shared_ptr<PictureParameterSet> pps) :
			Vps(vps),
			Pps(pps),
			Sps(sps)
		{

		}

		static ParametersBundle getDefaultParameters(size_t picWIdth, size_t picHeight)
		{
			auto vps = VideoParameterSetBank::instance().createNext();
			auto sps = SequenceParameterSetBank::instance().createNext();
			auto pps = PictureParameterSetBank::instance().createNext();

			sps->setPicSize(picWIdth, picHeight);

			return ParametersBundle(vps, sps, pps);
		}
	};
}