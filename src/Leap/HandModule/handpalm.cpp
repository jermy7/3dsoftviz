/**
 * Created by Patrik Berger on 13.11.2016.
 */
#include <easylogging++.h>
#include "Leap/HandModule/HandPalm.h"



Leap::HandPalm::HandPalm(float radius, osg::ref_ptr<osg::Group> handsGroup) {
    this->fingerGroup = new osg::Group();
    this->generateGeometry(radius);
    this->initStructure();

    // pridanie nodu dlane a groupy prstov do sceny
    handsGroup->addChild(static_cast<osg::Node*> (this));
    handsGroup->addChild(this->fingerGroup);
}

void Leap::HandPalm::initStructure() {
    LOG( INFO ) << "Leap/HandleModule/HandPalm/initStrucure()";
    if (this->fingerGroup.get()->getNumChildren() == 0) {
        int i = 0;

        // Create finger joint groups
        for(i = 0; i < 5; i++) {
            osg::ref_ptr<osg::Group> fingerJointGroup = new osg::Group();
            Joint* joint = new Joint(0, i, fingerJointGroup);
            this->fingerGroup->insertChild(i,fingerJointGroup);
        }
    }
}
