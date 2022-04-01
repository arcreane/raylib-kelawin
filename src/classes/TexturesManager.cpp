//
// Created by Arthur on 27/02/2022.
//

#include <iostream>

#include "TexturesManager.h"
#include "Utils.h"

TexturesManager::TexturesManager() {
    loadTexture("missing_texture");
    this->defaultTexture = this->textures["missing_texture"];
    this->defaultTextureCube = this->texturesCube["missing_texture"];
}

void TexturesManager::loadTexture(const std::string& name) {
    std::string asset = "../assets/"+name+".png";
    this->textures[name] = LoadTexture(asset.c_str());
}

Texture2D TexturesManager::getTexture(const std::string& name) {
    if (instance().unknownTextures.count(name) == 1) {
        return instance().defaultTexture;
    }
    auto iter = instance().textures.find(name);
    if (iter != instance().textures.end()) {
        return iter->second;
    } else if (file_exists("../assets/"+name+".png")) {
        instance().loadTexture(name);
        return instance().textures[name];
    } else {
        instance().unknownTextures.insert(name);
        std::cout << "NOPE" << std::endl;
        return instance().defaultTexture;
    }
}

TextureCubemap TexturesManager::getTextureCube(const std::string& name) {
    if (instance().unknownTextures.count(name) == 1) {
        return instance().defaultTexture;
    }
    auto iter = instance().textures.find(name);
    if (iter != instance().textures.end()) {
        return iter->second;
    } else if (file_exists("../assets/"+name+".png")) {
        instance().loadTexture(name);
        return instance().textures[name];
    } else {
        instance().unknownTextures.insert(name);
        std::cout << "NOPE" << std::endl;
        return instance().defaultTexture;
    }
}


