// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

/**
 * BMP implementation of the helper class
 */
class FBmpImageWrapper
	: public FImageWrapperBase
{
public:

	/**
	 * Default Constructor.
	 */
	FBmpImageWrapper(bool bInHasHeader = true, bool bInHalfHeight = false);

public:

	/** Helper function used to uncompress BMP data from a buffer */
	void UncompressBMPData( const ERGBFormat::Type InFormat, const int32 InBitDepth );

	/** 
	 * Load the header information, returns true if successful.
	 *
	 * @return true if successful
	 */
	bool LoadBMPHeader();

	/** 
	 * Load the sub-header information, returns true if successful.
	 *
	 * @return true if successful
	 */
	bool LoadBMPInfoHeader();

public:

	// FImageWrapper Interface

	virtual void Compress( int32 Quality ) override;
	virtual void Uncompress( const ERGBFormat::Type InFormat, int32 InBitDepth ) override;
	virtual bool SetCompressed( const void* InCompressedData, int32 InCompressedSize ) override;

private:

	/** Whether this file has a BMP file header */
	bool bHasHeader;

	/** BMP as a sub-format of ICO stores its height as half their actual size */
	bool bHalfHeight;
};