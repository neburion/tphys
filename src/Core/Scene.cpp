#include "core/Scene.hpp"
#include "core/Object.hpp"
#include <string>
#include <vector>
#include <unordered_map>

void Scene::addObject(std::unique_ptr<Object> toAdd){
    indexMap[toAdd->name] = objects.size();
    objects.push_back(std::move(toAdd));
}

void Scene::removeObject(Object &toRemove){
    int toRemoveAddress = indexMap[toRemove.name];

    objects[toRemoveAddress] = std::move(objects.back());
    indexMap[objects.back()->name] = toRemoveAddress;
    
    objects.pop_back();
    indexMap.erase(toRemove.name);
}

int Scene::getObejectsNumber(){
    return objects.size();
}

Object &Scene::getObjectByName(std::string toGet){
    return *objects.at(indexMap[toGet]);
}

Object& Scene::getObjectByIndex(int index){
    return *objects.at(index); 
}
