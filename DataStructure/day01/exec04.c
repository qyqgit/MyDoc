#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int		Val;
	struct node*	pNext;
} NODE;

typedef struct linkList {
	NODE	head;
	NODE	last;
} LINK_LIST;

typedef void(*CALLBACK)(NODE*);
typedef void(*CALLBACKEX)(NODE*, int);
typedef void(*CALLBACKEX_NODE)(LINK_LIST*, NODE*);

void linkListInit(LINK_LIST* pLinkList){
	pLinkList->head.pNext = &pLinkList->last; 
}
int linkListAddNode(LINK_LIST* pLinkList, int Val){
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	if(pNode){
		pNode->Val = Val;
		NODE* pTmp = NULL;
		pTmp = pLinkList->head.pNext;
		pLinkList->head.pNext = pNode;
		pNode->pNext = pTmp;
		return 0;
	}
	return -1;
}
void linkListRemoveNodeByIndex(int index){
	
}
NODE* linkListSelectParentNodeByPtr(LINK_LIST* pLinkList, NODE* pNode){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	for(pTmp = &pLinkList->head; pTmp != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		if(pMid == pNode)
			return pFirst;
	}
	return NULL;

}
void linkListRemoveNodeByPtr(LINK_LIST* pLinkList, NODE* pNode){//ok
	if(!pNode)
		return;
	NODE* pNodeParent = linkListSelectParentNodeByPtr(pLinkList, pNode);
	if(!pNodeParent)
		return;
	pNodeParent->pNext = pNode->pNext;
	printf("%d\n",pNode->Val);
	free(pNode);
	
	
}
void linkListRemoveNextNode(LINK_LIST* pLinkList, NODE* pNode){
	if(!pNode->pNext->pNext)
		return;
	NODE* pTmp = NULL;
	pTmp = pNode->pNext;
	pNode->pNext = pTmp->pNext;
	free(pTmp);
	
}

void linkListUpdateNode(NODE* pNode, int Val){
	if(!pNode)
		return;
	pNode->Val = Val;
}
NODE* linkListSelectParentNodeByIndex(LINK_LIST* pLinkList, int index){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	int num = 0;
	for(pTmp = &pLinkList->head; pMid != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp->pNext;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		if(num == index - 1)
			return pFirst;
		num++;
	}
	return NULL;

}

NODE* linkListSelectNodeByIndex(LINK_LIST* pLinkList, int index){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	int num = 0;
	for(pTmp = &pLinkList->head; pMid != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp->pNext;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		if(num == index)
			return pFirst;
		num++;
	}
	return NULL;

}
void forEachLinkList(LINK_LIST* pLinkList, CALLBACK pFunc){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	for(pTmp = &pLinkList->head; pTmp != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		pFunc(pMid);
	}


}
void forEachLinkListEx(LINK_LIST* pLinkList, CALLBACKEX pFunc, int Val){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	for(pTmp = &pLinkList->head; pMid != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp->pNext;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		pFunc(pFirst, Val);
	}


}
void forEachLinkListAndNodeRemove(LINK_LIST* pLinkList, CALLBACKEX_NODE pFunc){
	while(pLinkList->head.pNext != &pLinkList->last){
			pFunc(pLinkList, pLinkList->head.pNext);
		}
}
void forEachLinkListAndNode(LINK_LIST* pLinkList, CALLBACKEX_NODE pFunc){
	NODE* pFirst = NULL;
	NODE* pMid = NULL;
	NODE* pThrid = NULL;
	NODE* pTmp = NULL;
	for(pTmp = &pLinkList->head; pTmp != &pLinkList->last; pTmp = pTmp->pNext){
		pFirst = pTmp;
		pMid = pFirst->pNext;
		pThrid = pMid->pNext;
		pFunc(pLinkList, pMid);
	}


}
void linkListPrintNode(NODE* pNode){
	printf("%d\n", pNode->Val);
}
int main(){
	LINK_LIST linkList = {0};
	linkListInit(&linkList);
	linkList.head.Val = 9998;
	linkList.last.Val = 9999;
	linkListAddNode(&linkList, 0);
	linkListAddNode(&linkList, 1);
	linkListAddNode(&linkList, 2);
	linkListAddNode(&linkList, 3);
	linkListAddNode(&linkList, 4);
	linkListAddNode(&linkList, 5);
	linkListAddNode(&linkList, 6);
	linkListAddNode(&linkList, 7);
	linkListAddNode(&linkList, 8);
	linkListAddNode(&linkList, 9);
	//forEachLinkListEx(&linkList, linkListUpdateNode, 8);
	//linkListSelectNodeByIndex(&linkList, 1)->Val = 23;
	//linkListSelectNodeByIndex(&linkList, 0)->Val = 123;
	//linkListSelectNodeByIndex(&linkList, 4)->Val = 223;
	//linkListUpdateNode(linkListSelectNodeByIndex(&linkList, 4),566);
	forEachLinkList(&linkList, linkListPrintNode);
	forEachLinkListAndNodeRemove(&linkList, linkListRemoveNodeByPtr);
	forEachLinkList(&linkList, linkListPrintNode);
	getchar();
}

