#include "TextureHolder.h"

// include the "assert feature"
#include <assert.h>
TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}
Texture& TextureHolder::GetTexture(string const& filename)
{
	// get a reference to m_Textures using m_s_Instance
	auto& m = m_s_Instance->m_Textures;
	// auto is the equivalent of map<string, Texture>
	// Create an interator to hold a key-value-pair (Kvp)
	// and search for the required kvp
	// using the passed in file name
	auto keyValuePair = m.find(filename);
	// auto is equivalent of map<string, Texture>::iterator

	// Did we find a match?
	if (keyValuePair != m.end())
	{
	// yes
	// Return the texture,
	// the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
	// file name not found
	// Create a new key value pair using the filename
		auto& texture = m[filename];
	// Load the texture from file in the usual way
		texture.loadFromFile(filename);
	// Return the texture to the calling code
		return texture;
	}
}